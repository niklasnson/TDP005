#include "level.h"

Level::Level(Texture texture, SDL_Renderer* renderer, int const& level, bool & lost, bool & quit, int & score, int const& speed, int const& freq):
   texture{texture}, renderer{renderer}, level{level}, lost{lost}, quit{quit}, score{score}, fm_speed{speed},
   fm_frequency{freq}, em_speed{0}, em_frequency{0}  
{
   run(); //object runs the level on initiation
}

void Level::init()
{
   //calculates difficulty of enemy missiles
   em_speed = 2 + ((level-1)/3);
   em_frequency = 1000 - (level * 100);
	
   //create game_objects
   m[6].push_back(new Player{texture.get_texture("sprites/fodder.png"), Point{575, 750}, renderer, Point{575, 750}, 32, 32, 0});
   m[1].push_back(new House{texture.get_texture("sprites/house_hi.png"), Point{21, 704}, renderer, 96, 96, 0});
   m[1].push_back(new House{texture.get_texture("sprites/house_hi.png"), Point{140, 704}, renderer, 96,96, 0});
   m[1].push_back(new House{texture.get_texture("sprites/house_hi.png"), Point{240, 704}, renderer, 96, 96, 0});
   m[1].push_back(new House{texture.get_texture("sprites/house_hi.png"), Point{1010, 704}, renderer, 96, 96, 0});
   m[1].push_back(new House{texture.get_texture("sprites/house_hi.png"), Point{890, 704}, renderer, 96, 96, 0});
   m[1].push_back(new House{texture.get_texture("sprites/house_hi.png"), Point{770, 704}, renderer, 96, 96 ,0});
   m[6].push_back(new Static{texture.get_texture("sprites/armytruck.png"), Point{520, 768}, renderer, 96, 32, 0});
}

void Level::run()
{
   init();
	
   //make mouse cursor
   SDL_Texture* cursor;
   SDL_Surface* loaded_surface = IMG_Load("sprites/aim.png");
   cursor = SDL_CreateTextureFromSurface(renderer, loaded_surface);
   SDL_FreeSurface(loaded_surface);
   
   SDL_ShowCursor(0);
   SDL_Rect cursor_hitbox;
   SDL_QueryTexture(cursor, NULL, NULL, &cursor_hitbox.w, &cursor_hitbox.h);
   if (cursor == nullptr)
      std::cout << "FAILEDTOLOAD cursor" << std::endl;

   bool won{false};
   int timer{0};
   int game_time{ 3000 + (150 * level) };
   SDL_Event e;
   unsigned int last_time_e = 0;
   unsigned int last_time_m = 0;
   bool has_spawned{false};
   unsigned int current_time;
   bool powerup{false};
   bool* pow{&powerup};
   int timeremaining{3000+(150*level)};
   bool is_on_paus{false};

   while(!lost && !won && !quit)
   {
      if (is_on_paus) //pause game
      {
	 while (SDL_PollEvent( & e ) !=0 ) 
	 {
	    if (e.type == SDL_KEYDOWN) 
	    {
	       is_on_paus = false; 
	    }
	 }
      }
      else
      {
	 //som housekeeping, generate random numbers, count time etc
	 timer += 1;
	 std::random_device rd;
	 std::mt19937 gen(rd());
	 std::uniform_int_distribution<int> dis(1, 40);
	 std::uniform_int_distribution<int> dis2(1, 2000);
	 current_time = SDL_GetTicks();
			
	 //random spawn of enemy missiles
	 if (dis(gen) == 40 && (current_time > last_time_e + em_frequency))
	 {		
	    m[3].push_back(new Enemy_missile{texture, texture.get_texture("sprites/enemy2.png"), renderer, em_speed, m, 21, 69, 20});
	    last_time_e = current_time;
	 }
	 //random spawn of powerup
	 if (dis2(gen) == 2000 && has_spawned==false)
	 {		
	    m[3].push_back(new Powerup{texture, texture.get_texture("sprites/powerup.png"), renderer, 2, m, powerup, 40, 60, 0});
	    has_spawned = true;
	 }

	 //check for user input
	 while( SDL_PollEvent( &e ) != 0 )
	 {
	    //User requests quit
	    if( e.type == SDL_QUIT )
	    {
	       quit = true;
	    }

	    if (e.type == SDL_KEYDOWN) 
	    {
	       is_on_paus = true; 
	    }
	    //fire missiles
	    if(e.type == SDL_MOUSEBUTTONUP && (current_time > last_time_m + fm_frequency))
	    {	
	       if (!powerup)
	       {
		  Point mouse_location{e.button.x, e.button.y};
		  Marker* mark = new Marker(texture.get_texture("sprites/marker.png"), mouse_location, renderer, 15, 15, 20);
		  m[2].push_back(mark);
		  m[4].push_back(new Friendly_missile{texture, texture.get_texture("sprites/player.png"), Point{575, 740}, renderer, mouse_location, fm_speed, m, mark, pow, 15, 45, 20});
		  last_time_m = current_time;
	       }
	       //this is for powerup missiles
	       else
	       {
		  Point mouse_location{e.button.x, e.button.y};
		  Marker* mark = new Marker(texture.get_texture("sprites/marker.png"), mouse_location, renderer, 15, 15, 20);
		  m[2].push_back(mark);
		  m[4].push_back(new Super_friendly_missile{texture, texture.get_texture("sprites/playerp.png"), Point{575, 740}, renderer, mouse_location, fm_speed, m, mark, pow, 15, 45, 20});
		  last_time_m = current_time;				
	       }
	    }
	 }

	 SDL_RenderClear(renderer);

	 //check if objects in vectors are destroyed, and deletes them if they are	
	 for(std::pair<const int, std::vector<Game_object*>>& a : m)
	 {
	    for(std::vector<Game_object*>::iterator it{a.second.begin()}; it != a.second.end();)
	    {
	       if (!(*it) -> is_destroyed())
	       {
		  (*it) -> update();
		  ++it;
	       }
	       else
	       {
		  Enemy_missile* missile;
		  missile = dynamic_cast<Enemy_missile*>(*it);
		  if(missile != nullptr)
		  {
		     if (!missile -> get_hit_house())
		     {
			score += 2750;
		     }
		     else
		     {
			//score -= 150;
		     }
		  }
		  Game_object* todel = *it;
		  it = a.second.erase(it);
		  delete todel;
		  for(std::pair<const int, std::vector<Game_object*>>& a : m)
		  {
		     for(std::vector<Game_object*>::iterator it{a.second.begin()}; it != a.second.end();)
		     {
			if (!(*it) -> is_destroyed())
			{
			   (*it) -> update();
			   ++it;
			}
			else
			{
			   Enemy_missile* missile;
			   missile = dynamic_cast<Enemy_missile*>(*it);
			   if(missile != nullptr)
			   {
			      if (!missile -> get_hit_house())
			      {
				 score += 2750;
			      }
			      else
			      {
				 //score -= 150;
			      }
			   }
			   Game_object* todel = *it;
			   it = a.second.erase(it);
			   delete todel;
			}
		     }
		  }
	       }
	    }
	 }

	 //Deletes all text 
	 for(std::vector<Text*>::iterator it{t.begin()}; it != t.end();)
	 {
	    Text* todel = *it; 
	    it = t.erase(it);
	    delete todel; 
	 }

	 //creates text to print on screen
	 std::ostringstream str_data;

	 timeremaining -= 1;
	 str_data << "SCORE: " << std::setw(9) << std::setfill('0') << score << " LEVEL: " << std::setw(3) << std::setfill('0') << level << " TIME: " << std::setw(5) << std::setfill('0') << timeremaining;
	 t.push_back(new Text{str_data.str(), Point{16,16}, renderer});

	 //prints text on screen
	 if (powerup == true) 
	 {
	    t.push_back(new Text{"POWER MODE", Point{975, 16}, renderer});	
	 }
	 //
	 for(std::vector<Text*>::iterator it{t.begin()}; it != t.end(); ++it) 
	 {
	    (*it) -> update();
	 }
			
	 //draw mouse cursor on scrren
	 SDL_GetMouseState(&cursor_hitbox.x, &cursor_hitbox.y);
	 cursor_hitbox.x += 2;
	 cursor_hitbox.y += 2;
	 SDL_RenderCopy(renderer, cursor, NULL, &cursor_hitbox);

	 SDL_RenderPresent(renderer);
	 SDL_Delay(10);


	 //check if the player lost or won
	 for(auto h : m[1])
	 {
	    if((dynamic_cast<House*>(h)) -> get_state())
	    {
	       lost=false;
	       break;
	    }
	    else
	    {
	       lost=true;
	    }
	 }
	 if (lost || timer > game_time)
	 {
	    for(std::pair<const int, std::vector<Game_object*>>& a : m)
	    {
	       for(std::vector<Game_object*>::iterator it{a.second.begin()}; it != a.second.end();)
	       {	
		  Game_object* todel = *it;
		  it = a.second.erase(it);
		  delete todel;
	       }
	    }
	 }
	 if (timer > game_time)
	 {
	    won = true;
	 }
      }
   }
   //cleanup time
   SDL_DestroyTexture(cursor);
   for(std::pair<const int, std::vector<Game_object*>>& a : m)
   {
      for(std::vector<Game_object*>::iterator it{a.second.begin()}; it != a.second.end();)
      {
	 Game_object* todel = *it;
	 it = a.second.erase(it);
	 delete todel;
      }
   }
   for(std::vector<Text*>::iterator it{t.begin()}; it != t.end();)
   {
      Text* todel = *it; 
      it = t.erase(it);
      delete todel; 
   }

}

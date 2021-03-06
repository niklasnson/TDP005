#include "game.h"

Game::Game(SDL_Renderer* renderer,
	   int level,
	   int & score,
	   bool & quit,
	   Texture texture):
   Game_state(renderer, level, quit, texture),
   score{score}
{
   init();//runs automaitcally when object is initiated
}

void Game::init()
{
   bool lost{false};
   bool quit{false};
	
   int fm_speed{4};
   int fm_frequency{500};
   while(!lost && !quit)
   {
      Level gamelevel{texture, renderer, get_level(), lost, quit, score, fm_speed, fm_frequency};
      if (!lost && !quit)
      {
	 Powerup_screen(fm_speed, fm_frequency, quit);//lets player level up
	 level = level + 1;
      }
   }
   if (lost && !quit) 
   {
      End_screen(score);	
   }
}

/// Shows end screen to player.
void Game::End_screen(int const& score)
{ 
   SDL_ShowCursor(0);
   SDL_Event event;
   bool done{false};
   t.clear();

   if (score < 100) 
   {
      t.push_back(new Text{"Are you working for the enemy?!", Point{400, 350}, renderer});
   }
   else 
   {
      t.push_back(new Text{"Nice try!", Point{530, 350}, renderer});
   }

   t.push_back(new Text{"Press any key", Point{500, 370}, renderer});
	
   SDL_RenderClear(renderer);
	
   while(!done && !quit) 
   {
      for(std::vector<Text*>::iterator it{t.begin()}; it != t.end();) 
      {
	 (*it) -> update(); 
	 ++it;
      }
	
      while( SDL_PollEvent(&event) !=0) 
      {
	 switch( event.type )
	 {
	 case SDL_KEYUP: 
	    done = true; 
	    break;
	 }
	 if( event.type == SDL_QUIT )
	 {
	    quit = true;
	 }
      }
      SDL_RenderPresent(renderer);
      SDL_Delay(10);
   }
   for(std::vector<Text*>::iterator it{t.begin()}; it != t.end();)
   {
      Text* todel = *it; 
      it = t.erase(it);
      delete todel; 
   }
}

/// Shows level-up screen to player.
void Game::Powerup_screen(int & speed, int & frequency, bool & quit)
{
   SDL_Event e;
   SDL_ShowCursor(1);

   m[1].push_back(new House{texture.get_texture("sprites/box.png"), Point{400, 350}, renderer, 96, 96, 0});
   m[1].push_back(new House{texture.get_texture("sprites/box.png"), Point{600, 350}, renderer, 96, 96, 0});
   t.push_back(new Text{"Faster!", Point{410, 450}, renderer});
   t.push_back(new Text{"Harder!", Point{607, 450}, renderer});
   t.push_back(new Text{"The motherland thanks you, select new powerups!", Point{260, 200}, renderer});
   bool done{false};

   while(!done && !quit) 
   {
      SDL_RenderClear(renderer); 		
      for(std::pair<const int, std::vector<Game_object*>>& a : m)
      {
	 for(std::vector<Game_object*>::iterator it{a.second.begin()}; it != a.second.end();)
	 {
	    (*it) -> update();
	    ++it;
	 }
	 for(std::vector<Text*>::iterator it{t.begin()}; it != t.end();) 
	 {
	    (*it) -> update(); 
	    ++it;
	 }
      }
    
      while (SDL_PollEvent(&e) != 0) 
      {
	 if(e.type == SDL_MOUSEBUTTONUP)
	 {
	    int x, y;
	    SDL_GetMouseState(&x, &y);
	    SDL_Rect selection_speed; 
	    selection_speed.x = 400;
	    selection_speed.y = 350;
	    selection_speed.w = 96;
	    selection_speed.h = 96;
	    SDL_Rect selection_frequency;
	    selection_frequency.x = 600; 
	    selection_frequency.y = 350; 
	    selection_frequency.w = 96;
	    selection_frequency.h = 96; 
				
	    if (x >= selection_speed.x && x < selection_speed.x + selection_speed.w &&
		y >= selection_speed.y && y < selection_speed.y + selection_speed.h)
	    {
	       speed = speed + 1;
	       done = true; 
	    }

	    if (x >= selection_frequency.x && x < selection_frequency.x + 
		selection_frequency.w && y >= selection_frequency.y && 
		y < selection_frequency.y + selection_frequency.h)
	    {
	       frequency = frequency - 50; 
	       done = true; 
	    }
	 }
	 if(e.type == SDL_QUIT) 
	 {
	    quit = true; 
	 }
      }
      SDL_RenderPresent(renderer);
      SDL_Delay(10);
   }

   //cleanup
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

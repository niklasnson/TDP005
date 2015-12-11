#include "enemy_missile.h"
#include "collisionable.h"
#include "aabb.h"
#include "marker.h"
#include "game_state.h"
#include "game.h"
#include <map>
#include <random>
#include <chrono>
#include <vector>
#include "player.h"
#include "house.h"
#include "friendly_missile.h"
#include "text.h"
#include "powerup.h"
#include "level.h"
#include "text.h"
#include <sstream>  


using namespace std;

Level::Level(SDL_Renderer* renderer, int level, bool & lost, bool & quit, int & score, int & speed, int & freq):
  renderer{renderer}, level{level}, lost{lost}, quit{quit}, score{score}, fm_speed{speed},
	fm_frequency{freq}, em_speed{0}, em_frequency{0}  
{
  run();
}

void Level::init()
{
	em_speed = 1 + level;
	em_frequency = 1000 - (level * 50);

  m[6].push_back(new Player{"sprites/fodder.png", Point{575, 750}, renderer, Point{575, 750}, 32, 32, 0});
  m[1].push_back(new House{"sprites/house.png", Point{21, 704}, renderer, 96, 96, 0});
  m[1].push_back(new House{"sprites/house.png", Point{140, 704}, renderer, 96,96, 0});
  m[1].push_back(new House{"sprites/house.png", Point{240, 704}, renderer, 96, 96, 0});
  m[1].push_back(new House{"sprites/house.png", Point{1010, 704}, renderer, 96, 96, 0});
  m[1].push_back(new House{"sprites/house.png", Point{890, 704}, renderer, 96, 96, 0});
  m[1].push_back(new House{"sprites/house.png", Point{770, 704}, renderer, 96, 96 ,0});
  m[6].push_back(new Static{"sprites/armytruck.png", Point{520, 768}, renderer, 96, 32, 0});

	//t.push_back(new Text{"", Point{700, 10}, renderer});

}

void Level::run()
{
	init();

  SDL_Texture* cursor;
  SDL_Surface* loaded_surface = IMG_Load("sprites/aim.png");
  cursor = SDL_CreateTextureFromSurface(renderer, loaded_surface);
  SDL_FreeSurface(loaded_surface);
  SDL_ShowCursor(0);

  SDL_Rect cursor_hitbox;
  SDL_QueryTexture(cursor, NULL, NULL, &cursor_hitbox.w, &cursor_hitbox.h);
  if (cursor == nullptr)
    cout << "FAILEDTOLOAD cursor" << endl;

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

  while(!lost && !won && !quit)
    {
			timer += 1;

      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<int> dis(1, 40);
      std::uniform_int_distribution<int> dis2(1, 2000);
      current_time = SDL_GetTicks();
			
      if (dis(gen) == 40 && (current_time > last_time_e + em_frequency))
			{		
	  		m[3].push_back(new Enemy_missile{"sprites/enemy2.png", renderer, em_speed, m, 21, 69, 20});
	  		last_time_e = current_time;
			}

      if (dis2(gen) == 2000 && has_spawned==false)
			{		
	  		m[3].push_back(new Powerup{"sprites/powerup.png", renderer, 2, m, powerup, 40, 60, 0});
	  		has_spawned = true;
			}

			while( SDL_PollEvent( &e ) != 0 )
			{
	  		//User requests quit
	  		if( e.type == SDL_QUIT )
	    	{
	     		quit = true;
	    	}
	  		if(e.type == SDL_MOUSEBUTTONUP && (current_time > last_time_m + fm_frequency))
	    	{	
	     		if (!powerup)
					{
		  			Point mouse_location{e.button.x, e.button.y};
		 		 		Marker* mark = new Marker("sprites/marker.png", mouse_location, renderer, 15, 15, 20);
		 				m[2].push_back(mark);
		  			m[4].push_back(new Friendly_missile{"sprites/player.png", Point{575, 740}, renderer, mouse_location, fm_speed, m, mark, pow, 15, 45, 20});
		  			last_time_m = current_time;
					}
	      	else
					{
		  			Point mouse_location{e.button.x, e.button.y};
		  			Marker* mark = new Marker("sprites/marker.png", mouse_location, renderer, 15, 15, 20);
		  			m[2].push_back(mark);
		  			m[4].push_back(new Friendly_missile{"sprites/playerp.png", Point{575, 740}, renderer, mouse_location, fm_speed + 2, m, mark, pow, 15,42, 20});
		  			last_time_m = current_time;				
					}
	   		 }
				}

      SDL_RenderClear(renderer);
	
      for(pair<const int, vector<Game_object*>>& a : m)
			{
	  		for(vector<Game_object*>::iterator it{a.second.begin()}; it != a.second.end();)
	    	{
	 				if (!(*it) -> is_destroyed())
					{
		  			(*it) -> update();
		  			++it;
					}
	      	else
					{
		  			Game_object* todel = *it;
		  			it = a.second.erase(it);
					  delete todel;
					}
		    }
			}

			for(vector<Text*>::iterator it{t.begin()}; it != t.end();)
			{
				Text* todel = *it; 
				it = t.erase(it);
				delete todel; 
			}
			//
			std::ostringstream str_data;
			timeremaining -= 1;
			str_data << "SCORE: " << score << " LEVEL: " << level << " TIME: " << timeremaining;
			t.push_back(new Text{str_data.str(), Point{16,16}, renderer});
			if (powerup == true) 
			{
				t.push_back(new Text{"POWER MODE", Point{975, 16}, renderer});	
			}
			//
			for(vector<Text*>::iterator it{t.begin()}; it != t.end(); ++it) 
			{
				(*it) -> update();
			}

      SDL_GetMouseState(&cursor_hitbox.x, &cursor_hitbox.y);
      cursor_hitbox.x += 2;
      cursor_hitbox.y += 2;
      SDL_RenderCopy(renderer, cursor, NULL, &cursor_hitbox);

      SDL_RenderPresent(renderer);
      SDL_Delay(10);

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
	  		for(pair<const int, vector<Game_object*>>& a : m)
				{
	  			for(vector<Game_object*>::iterator it{a.second.begin()}; it != a.second.end();)
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
				cout << "VICTORYRRRRRRRRRRRRREYYYYYYYYYYYYYYY" << endl;
			}
		}
 	}


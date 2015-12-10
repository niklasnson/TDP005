#include "game.h"
#include <vector>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "static.h"
#include "screen_dimensions.h"
#include "rotatable.h"
#include "point.h"
#include "player.h"
#include "missile.h"
#include "house.h"
#include "game_object.h"
#include "friendly_missile.h"
#include "enemy_missile.h"
#include "collisionable.h"
#include "aabb.h"
#include "marker.h"
#include "game_state.h"
#include "game.h"

#include <map>
#include <random>
#include <chrono>
#include "powerup.h"

using namespace std;

Game::Game(SDL_Renderer* r, int l):Game_state(r, l)
{
	init();
}

void Game::init()
{
	bool lost{false};
	while(!lost)
	{


		SDL_Texture* cursor;
		SDL_Surface* loaded_surface = IMG_Load("sprites/aim.png");
		cursor = SDL_CreateTextureFromSurface(renderer, loaded_surface);
		SDL_FreeSurface(loaded_surface);
		SDL_ShowCursor(0);

		SDL_Rect cursor_hitbox;
		SDL_QueryTexture(cursor, NULL, NULL, &cursor_hitbox.w, &cursor_hitbox.h);
		if (cursor == nullptr)
			cout << "FAILEDTOLOAD cursor" << endl;

		m[6].push_back(new Player{"sprites/clauncher.png", Point{555, 700}, renderer, Point{520, 690}, 27, 63, 0});
		m[1].push_back(new House{"sprites/house.png", Point{21, 704}, renderer, 96, 96, 0});
		m[1].push_back(new House{"sprites/house.png", Point{140, 704}, renderer, 96,96, 0});
		m[1].push_back(new House{"sprites/house.png", Point{240, 704}, renderer, 96, 96, 0});
		m[1].push_back(new House{"sprites/house.png", Point{1010, 704}, renderer, 96, 96, 0});
		m[1].push_back(new House{"sprites/house.png", Point{890, 704}, renderer, 96, 96, 0});
		m[1].push_back(new House{"sprites/house.png", Point{770, 704}, renderer, 96, 96 ,0});
		m[6].push_back(new Static{"sprites/bunker.png", Point{520, 704}, renderer, 96, 96, 0});
		//m[6].push_back(new Text{"text", Point{500, 500}, renderer}); 
		bool quit{false};
		SDL_Event e;
	
		unsigned int last_time_e = 0;
		unsigned int last_time_m = 0;
		bool has_spawned{false};
		unsigned int current_time;
		bool powerup{false};
		bool* pow{&powerup};

		
		while(!quit)
		{

			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<int> dis(1, 40);
			std::uniform_int_distribution<int> dis2(1, 2000);
			current_time = SDL_GetTicks();
			
			// text function call 

			// /text function call 

			if (dis(gen) == 40 && (current_time > last_time_e + 900))
			{		
				m[3].push_back(new Enemy_missile{"sprites/enemy2.png", renderer, 3, m, 21, 69, 20});
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
				
				if(e.type == SDL_MOUSEBUTTONUP && (current_time > last_time_m + 500))
				{	
					if (!powerup)
					{
						Point mouse_location{e.button.x, e.button.y};
						Marker* mark = new Marker("sprites/marker.png", mouse_location, renderer, 15, 15, 20);
						m[2].push_back(mark);
						m[4].push_back(new Friendly_missile{"sprites/player.png", Point{555, 700}, renderer, mouse_location, 5, m, mark, pow, 15, 45, 20});
						last_time_m = current_time;
					}
					else
					{
						Point mouse_location{e.button.x, e.button.y};
						Marker* mark = new Marker("sprites/marker.png", mouse_location, renderer, 15, 15, 20);
						m[2].push_back(mark);
						m[4].push_back(new Friendly_missile{"sprites/playerp.png", Point{555, 700}, renderer, mouse_location, 8, m, mark, pow, 15,42, 20});
					
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

		SDL_GetMouseState(&cursor_hitbox.x, &cursor_hitbox.y);
		cursor_hitbox.x += 2;
		cursor_hitbox.y += 2;
		SDL_RenderCopy(renderer, cursor, NULL, &cursor_hitbox);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
		}


		lost=true;
	}


}

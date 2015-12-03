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
#include "collisionable.h"
#include "aabb.h"



using namespace std;

int main()
{
	Screen_dimensions sd;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	window = SDL_CreateWindow( "KOMRAD KOMMAND", SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, sd.SCREEN_W, 
					sd.SCREEN_H, SDL_WINDOW_SHOWN );
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	SDL_SetRenderDrawColor(renderer, 255, 255, 226, 0);

	Point point_house_0{21, sd.SCREEN_H - 96};
	Point point_house_1{140, sd.SCREEN_H - 96};
	Point point_house_2{240, sd.SCREEN_H - 96};
	Point point_house_3{1010,sd. SCREEN_H - 96};
	Point point_house_4{890, sd.SCREEN_H - 96};
	Point point_house_5{770, sd.SCREEN_H - 96};
	Point point_player_base{500, sd.SCREEN_H - 96};
	Point point_player_rotatable{500, sd.SCREEN_H -70};

	Point missile{50, 50};
	Point missilet{500, 500};
	Point speed{5, 5};

	vector<Game_object*> v;

	v.push_back(new Player{"sprites/louncher.png", point_player_rotatable, renderer, point_player_rotatable});
	v.push_back(new House{"sprites/house.png", point_house_0, renderer});
	v.push_back(new House{"sprites/house.png", point_house_1, renderer});
	v.push_back(new House{"sprites/house.png", point_house_2, renderer});
	v.push_back(new House{"sprites/house.png", point_house_3, renderer});
	v.push_back(new House{"sprites/house.png", point_house_4, renderer});
	v.push_back(new House{"sprites/house.png", point_house_5, renderer});
	v.push_back(new Static{"sprites/bunker.png", point_player_base, renderer});

	bool quit{false};
	SDL_Event e;

	while(!quit)
	{
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			if(e.type == SDL_MOUSEBUTTONUP)
			{
				Point mouse_location{e.button.x, e.button.y};
				v.push_back(new Friendly_missile{"sprites/player.png", point_player_rotatable, renderer, mouse_location, 4});
			}
		}
		SDL_RenderClear(renderer); 

		for(vector<Game_object*>::iterator it{v.begin()}; it != v.end();)
		{
			if (!(*it) -> is_destroyed())
			{
				(*it) -> update();
				++it;
			}
			else
			{
				cout << "BEFORE NULL" << endl;
				//o -> release_texture();
				Game_object* todel = *it;
				it = v.erase(it);
				delete todel;				
			}
		}

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	return 0;
}

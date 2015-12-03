#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "game_object.h"
#include "point.h"
#include "collisionable.h"
#include "aabb.h"
#include "rotatable.h"
#include "player.h"
#include "missile.h"

#include "friendly_missile.h"

#include "house.h"
#include <iostream>

using namespace std;

int main()
{
	int SCREEN_HEIGHT{800};
	int SCREEN_WIDTH{1130};
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	window = SDL_CreateWindow( "KOMRAD KOMMAND", SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	SDL_SetRenderDrawColor(renderer, 255, 255, 226, 0);
	Point house0{21, SCREEN_HEIGHT - 96};
	Point house1{140, SCREEN_HEIGHT - 96};
	Point house2{240, SCREEN_HEIGHT - 96};
	Point house3{1010, SCREEN_HEIGHT - 96};
	Point house4{890, SCREEN_HEIGHT - 96};
	Point house5{770, SCREEN_HEIGHT - 96};
	Point player{500, 500};
	Point playert{400, 400};

	Point missile{50, 50};
	Point missilet{500, 500};
//	Point target1{500, 500};
//	Point target2{600, 500};
//	Point target3{300, 500};
//	Point friendly{400, 1000};
//	Point friendlyt{400, 0};
	Point speed{5, 5};

	vector<Game_object*> v;

	//Collisionable c{"boom.png", a, renderer};
	v.push_back(new Player{"cccp.png", player, renderer, playert});
	v.push_back(new Friendly_missile{"missile.png", missilet, renderer, missile, 4}); 
	v.push_back(new House{"sprites/house.png", house0, renderer});
	v.push_back(new House{"sprites/house.png", house1, renderer});
	v.push_back(new House{"sprites/house.png", house2, renderer});
	v.push_back(new House{"sprites/house.png", house3, renderer});
	v.push_back(new House{"sprites/house.png", house4, renderer});
	v.push_back(new House{"sprites/house.png", house5, renderer});

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
				v.push_back(new Friendly_missile{"missile.png", player, renderer, mouse_location, 4});
			}
		}
		SDL_RenderClear(renderer); 

		for(Game_object* o : v)
		{
			if not(o -> is_destroyed)
				o -> update();
			//else
			//destroy object and remove pointer
		}

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	return 0;
}

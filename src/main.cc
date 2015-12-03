#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game_object.h"
#include "point.h"
#include "collisionable.h"
#include "aabb.h"
#include "rotatable.h"
#include "player.h"
#include "missile.h"
#include "friendly_missile.h"
#include <iostream>

int main()
{
	int SCREEN_HEIGHT{800};
	int SCREEN_WIDTH{1131};
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	window = SDL_CreateWindow( "KOMRAD KOMMAND", SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	SDL_SetRenderDrawColor(renderer, 255, 255, 226, 0);
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

	//Collisionable c{"boom.png", a, renderer};
	Player b{"cccp.png", player, renderer, playert};
	Friendly_missile m{"missile.png", missilet, renderer, missile, 4}; 
//	Missile mm{"missile.png", friendly, renderer, friendlyt, 4}; 
//	Missile mmm{"missile.png", missile, renderer, target3, 4}; 
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
		}
		SDL_RenderClear(renderer); 
		//c.update();	
		b.update();
		m.update();
		//mm.update();
		//mmm.update();
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	return 0;
}

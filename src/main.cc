#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game_object.h"
#include "point.h"
#include "collisionable.h"
#include "aabb.h"
#include "rotatable.h"
#include "player.h"
#include "missile.h"
#include "house.h"
#include <iostream>

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
	Point missile{500, 100};
	Point target1{500, 500};
	Point target2{600, 500};
	Point target3{300, 500};
	Point speed{5, 5};

	//Collisionable c{"boom.png", a, renderer};
	Player b{"cccp.png", player, renderer, target1};
	Missile m{"missile.png", missile, renderer, target1, 4}; 
	Missile mm{"missile.png", missile, renderer, target2, 4}; 
	Missile mmm{"missile.png", missile, renderer, target3, 4};
	House h0{"sprites/house.png", house0, renderer};
	House h1{"sprites/house.png", house1, renderer};
	House h2{"sprites/house.png", house2, renderer};
	House h3{"sprites/house.png", house3, renderer};
	House h4{"sprites/house.png", house4, renderer};
	House h5{"sprites/house.png", house5, renderer};

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
		mm.update();
		mmm.update();
		h0.update(); 
		h1.update(); 
		h2.update(); 
		h3.update(); 
		h4.update(); 
		h5.update();
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	return 0;
}

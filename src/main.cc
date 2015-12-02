#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game_object.h"
#include "point.h"
#include "collisionable.h"
#include "aabb.h"
#include <iostream>

int main()
{
	int SCREEN_HEIGHT{800};
	int SCREEN_WIDTH{600};
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	window = SDL_CreateWindow( "KICKASS GAME", SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	Point a{1, 1};
	Point s{3, 4};
	Game_object c{"boom.png", a, renderer};

	Collisionable b{"cccp.png", a, renderer};


	SDL_RenderClear(renderer); 
	c.draw();	

	b.draw(); 
	SDL_RenderPresent(renderer);
	SDL_Delay(4000);
	return 0;
}

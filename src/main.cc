
#include <vector>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
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
#include "start.h"
#include "endgame.h"
#include <map>
#include <random>
#include <chrono>


using namespace std;

int main()
{
	Screen_dimensions sd;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	window = SDL_CreateWindow( "KOMRAD KOMMAND", SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, sd.SCREEN_W, 
					sd.SCREEN_H, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	SDL_SetRenderDrawColor(renderer, 255, 255, 226, 0);
		
	if(TTF_Init()==-1) 
	{
    cout << "TTF_Init: error!" << endl;
    exit(2);
	}
	
	SDL_Texture* cursor;
	SDL_Surface* loaded_surface = IMG_Load("sprites/aim.png");
	cursor = SDL_CreateTextureFromSurface(renderer, loaded_surface);
	SDL_FreeSurface(loaded_surface);
	SDL_ShowCursor(0);

	SDL_Rect cursor_hitbox;
	SDL_QueryTexture(cursor, NULL, NULL, &cursor_hitbox.w, &cursor_hitbox.h);
	if (cursor == nullptr)
		cout << "FAILEDTOLOAD" << endl;


	//while(true)
	//{
		int score{100000};

		//Start s{renderer, 1};
		//Game g{renderer, 1, score};
		Endgame e{renderer, 1, score};
	//}
	return 0;
}

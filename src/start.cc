#include "start.h"
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

Start::Start(SDL_Renderer* r, int l):Game_state(r, l)
{
	init();
}

void Start::init()
{
	SDL_Texture* cursor;
	SDL_Surface* loaded_surface = IMG_Load("sprites/aim.png");
	cursor = SDL_CreateTextureFromSurface(renderer, loaded_surface);
	SDL_FreeSurface(loaded_surface);

	SDL_Rect cursor_hitbox;
	SDL_QueryTexture(cursor, NULL, NULL, &cursor_hitbox.w, &cursor_hitbox.h);
	if (cursor == nullptr)
		cout << "FAILEDTOLOAD cursor" << endl;SDL_ShowCursor(0);
	
	SDL_Event e;
	bool end{false};

	m[1].push_back(new House{"sprites/menu.png", Point{0, 0}, renderer, 96, 96, 0});

	while(!end)
	{
		SDL_RenderClear(renderer);

		while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT )
			{
				end = true;
			}
			if(e.type == SDL_MOUSEBUTTONUP)
			{
				end = true;
			}
		}


		for(auto p : m)
		{
			for(auto go:p.second)
			{
				go -> update();
			}
		}

	SDL_GetMouseState(&cursor_hitbox.x, &cursor_hitbox.y);
	cursor_hitbox.x += 2;
	cursor_hitbox.y += 2;
	SDL_RenderCopy(renderer, cursor, NULL, &cursor_hitbox);

	SDL_RenderPresent(renderer);
	SDL_Delay(10);
	}
}

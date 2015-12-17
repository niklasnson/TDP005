#include "variables.h"
#include "endgame.h"
#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

int main()
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	window = SDL_CreateWindow( "KOMRAD KOMMAND", SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, Variables::screen_width, 
					Variables::screen_height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	SDL_SetRenderDrawColor(renderer, 255, 255, 226, 0);
		
	if(TTF_Init()==-1) 
	{
    std::cout << "TTF_Init: error!" << std::endl;
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
		std::cout << "FAILEDTOLOAD" << std::endl;

	int score{0};
	bool quit{false};
	while(!quit)
	{
		Start s{renderer, 1, quit};
		if(quit)
			break;
		Game g{renderer, 1, score, quit};
		if(quit)
			break;
		Endgame e{renderer, 1, score, quit};
		if(quit)
			break;
	}
	return 0;
}

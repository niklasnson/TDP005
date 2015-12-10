#ifndef GAME_h
#define GAME_h

#include "game_state.h"
#include "game_object.h"
#include "text.h"
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>


class Game: public Game_state
{
public:
	Game(SDL_Renderer*, int);
	
	void init();

private:
	std::map<int, std::vector<Game_object*>> m;
	std::vector<Text*> t; 
};

#endif

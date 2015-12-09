#ifndef START_h
#define START_h

#include "game_state.h"
#include "game_object.h"
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>


class Start: public Game_state
{
public:
	Start(SDL_Renderer*, int);
	
	void init();

private:
	std::map<int, std::vector<Game_object*>> m;
};

#endif

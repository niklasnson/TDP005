#ifndef START_h
#define START_h

#include "game_state.h"
#include "game_object.h"
#include "missile.h"
#include <vector>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
class Start: public Game_state
{
public:
	Start(SDL_Renderer*, int, bool &);
	void init();

private:
	std::map<int, std::vector<Game_object*>> m;
};
#endif

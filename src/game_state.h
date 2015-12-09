#ifndef GAME_STATE_h
#define GAME_STATE_h

#include <map>
#include <random>
#include <chrono>
#include <vector>
#include <iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>


class Game_state
{
public:
	Game_state(SDL_Renderer*, int);
	virtual ~Game_state();
	void set_level(int);
	int get_level();

protected:
	SDL_Renderer* renderer;
	int level;
};

#endif

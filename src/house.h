#ifndef HOUSE_h
#define HOUSE_h

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "point.h"
#include "game_object.h"



class House : public Game_object
{
public:
	House(std::string, Point, SDL_Renderer*, int, int, int);
	void update(); 
	bool get_state(); 
	void set_state(bool);

private: 
	bool intact;
};
#endif

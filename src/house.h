#ifndef HOUSE_h
#define HOUSE_h

#include "game_object.h"
#include "point.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

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

#ifndef STATIC_H 
#define STATIC_H 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "point.h"
#include "game_object.h"

class Static : public Game_object
{
public:
	Static(std::string, Point, SDL_Renderer*, int, int, int);
	void update(); 
}; 
#endif 

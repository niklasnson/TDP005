#ifndef PLAYER_h 
#define PLAYER_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "point.h"
#include "rotatable.h"

class Player : public Rotatable 
{
public:
	Player(std::string, Point, SDL_Renderer*, Point, int, int, int);
	void update();
};
#endif

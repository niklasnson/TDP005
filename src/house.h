#ifndef HOUSE_h
#define HOUSE_h

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "collisionable.h"
#include "point.h"
#include "aabb.h"

class House : public Collisionable
{
public: 
	House(std::string, Point, SDL_Renderer*);  
	void update(); 
	bool get_state(); 
	void set_state(bool); 

private: 
	bool intact;
};
#endif

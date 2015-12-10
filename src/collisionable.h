#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H
#include <SDL2/SDL.h>
#include "point.h"
#include <SDL2/SDL_image.h>
#include "aabb.h"
#include <string>
#include "game_object.h"

class Collisionable : public Game_object
{
public:
	Collisionable(std::string, Point, SDL_Renderer*, int, int, int);
	void update(); 
	bool collision(AABB); 
	AABB make_bounding_box();

protected:
	AABB boundingbox;
};
#endif

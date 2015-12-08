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
		Collisionable(std::string, Point, SDL_Renderer*); 
		void update(); 
		bool collision(AABB); 
		AABB make_bounding_box();
		//virtual bool get_state();

	protected:
		AABB boundingbox;
};
#endif

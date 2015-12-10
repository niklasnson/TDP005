#include "collisionable.h"
#include "aabb.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

AABB Collisionable::make_bounding_box()
{
	AABB a{cords.x, cords.y, cords.x+200, cords.y+200};
	return a;
}

Collisionable::Collisionable(std::string i,
															Point crd, 
															SDL_Renderer* r,
															int sW, 
															int sH, 
															int sS
															):Game_object(i, crd, r, sW, sH, sS), 
															boundingbox{crd.x, crd.y, crd.x, crd.y}
{
	boundingbox = make_bounding_box(); 
}

void Collisionable::update()
{
	std::cout << "collisionable::update()" << std::endl; 
}

bool Collisionable::collision(AABB a)
{
	return boundingbox.intersect(a);
}

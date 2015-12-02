#include "collisionable.h"
#include "aabb.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


AABB Collisionable::make_bounding_box()
{
	int width;
	int height;
	SDL_QueryTexture(get_image(), NULL, NULL, &width, &height);
	
	return AABB a{cords.x, cords.y, cords.x+width, cords.y+height};
}

Collisionable::Collisionable(std::string s, Point crd, SDL_Renderer* r):Game_object(s, crd, r)
{
	boundingbox = make_bounding_box();
}

void Collisionable::update();
{
	draw();
}

bool Collisionable::collision(AABB a)
{
	return false;//AABB::will_collide(a);
}

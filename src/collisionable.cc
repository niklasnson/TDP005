#include "collisionable.h"
#include "aabb.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


AABB Collisionable::make_bounding_box()
{
	int width;
	int height;
	SDL_QueryTexture(get_image(), NULL, NULL, &width, &height);
		
	AABB a{cords.x, cords.y, cords.x+width, cords.y+height};
	return a;
}

Collisionable::Collisionable(std::string s, Point crd, SDL_Renderer* r):
		Game_object(s, crd, r), boundingbox{crd.x, crd.y, crd.x, crd.y}
	
{
	boundingbox = make_bounding_box();
}

void Collisionable::update()
{
	draw();
}

bool Collisionable::collision(AABB a)
{
	return boundingbox.intersect(a);
}

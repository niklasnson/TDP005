#include "collisionable.h"
#include "AABB.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image>


void make_bounding_box()
{
	int width;
	int height;
	SDL_QueryTexture(img, NULL, NULL, &width, &height);
	AABB a{cords.x, cords.y, width, height};
	return a;
}

Collisionable::Collisionable(std::string s, Point crd, SDL_Renderer* r):Game_object(s, crd, r)
{
	AABB = make_bounding_box();
}

bool Collisionable::collision(AABB a)
{
	return AABB::will_collide(a);
}

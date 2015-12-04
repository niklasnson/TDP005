#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "static.h"
#include "screen_dimensions.h"
#include "point.h"
#include "marker.h"
#include "sprite.h"


Marker::Marker(std::string i, Point crd, SDL_Renderer* r):Static(i, crd, r){
	sprite = new Sprite(i, cords, r, 15, 15, 15);
}

void Marker::update()
{
	sprite -> draw();
}


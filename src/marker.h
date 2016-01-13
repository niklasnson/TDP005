#ifndef MARKER_h 
#define MARKER_h
#include "point.h"
#include "static.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Marker : public Static 
{
public:
   /*!
    * Constructor for Marker.
    * @param filename, a string argument.
    * @param point, a Point object. 
    * @param renderer, a SDL_Renderer pointer.
    * @param sprite_width, a int argument.
    * @param sprite_height, a int argument.
    * @param sprite_speed, a int argument. 
    */
   Marker(SDL_Texture*, Point, SDL_Renderer*, int const&, int const&, int const&);
   void update();
};
#endif

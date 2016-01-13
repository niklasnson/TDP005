#ifndef STATIC_H 
#define STATIC_H 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "point.h"
#include "game_object.h"

/*! Objects that not move  */
class Static : public Game_object
{
public:
	  /*!
	 * Constructor for Static.
	 * @param texture - a SDL_Texture pointer.
	 * @param point - a Point object.
   * @param renderer - a SDL_Renderer pointer.
   * @param sprite_width - a int argument.
   * @param sprite_height - a int argument.
   * @param sprite_speed - a int argument. 
	 */
  Static(SDL_Texture*, Point, SDL_Renderer*, int const&, int const&, int const&);
	/// Update object
  void update(); 
}; 
#endif 

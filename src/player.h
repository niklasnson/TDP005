#ifndef PLAYER_h 
#define PLAYER_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "point.h"
#include "rotatable.h"

class Player : public Rotatable 
{
public:
  /*!
	 * Constructor for PowerupObject.
	 * @param filename, a string argument.
   * @param point, a Point object.
   * @param renderer, a SDL_Renderer pointer.
   * @param target, a Point object. 
   * @param sprite_width, a bool argument.
   * @param sprite_height, a int argument.
   * @param sprite_speed, a int argument. 
	 */
	Player(std::string const&, Point, SDL_Renderer*, Point, int const&, int const&, int const&);
	void update();
};
#endif

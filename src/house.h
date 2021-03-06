#ifndef HOUSE_h
#define HOUSE_h

#include "game_object.h"
#include "point.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class House : public Game_object
{
public:

  /*!
	 * Constructor for House.
   * @param texture - a SDL_Texture pointer.  
   * @param point - a Point object. 
   * @param renderer - a SDL_Renderer pointer.
   * @param sprite_width - a int argument. 
   * @param sprite_height - a int argument. 
   * @param sprite_speed - a int argument. 
	 */
	House(SDL_Texture*, Point, SDL_Renderer*, int const&, int const&, int const&);
	void update(); 
	bool get_state() const; 
	void set_state(bool);

private: 
	bool intact;  /*!< an bool value */
};
#endif

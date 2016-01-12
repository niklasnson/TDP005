#ifndef TEXT_h 
#define TEXT_h
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "point.h"
#include <string> 

/*! Used to show text on screen during the game */

class Text 
{
public: 
  /*!
	 * Constructor for Text.
	 * @param filename, a string argument.
	 * @param point, a Point object.
   * @param renderer, a SDL_Renderer pointer.
   * @param target, a Point object. 
   * @param speed, a int argument.
   * @param marker, a Marker object. 
   * @param powerup, a bool object. 
   * @param sprite_width, a int argument.
   * @param sprite_height, a int argument.
   * @param sprite_speed, a int argument. 
	 */
	Text(std::string const&, Point p, SDL_Renderer* r);
	~Text(); 
	/// Update object
  void update();

private:
	std::string stext;    
  Point position;
  SDL_Renderer* renderer;
};
#endif

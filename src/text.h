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
	 * @param stext - a string paramater. 
   * @param position - a Point object.
   * @param renderer - a SDL_Renderer pointer.
	 */
	Text(std::string const& stext, Point position, SDL_Renderer* renderer);
	~Text(); 
	/// Update object
  void update();

private:
	std::string stext;    
  Point position;
  SDL_Renderer* renderer;
};
#endif

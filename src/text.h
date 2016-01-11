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
  /// Create a TextClass
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

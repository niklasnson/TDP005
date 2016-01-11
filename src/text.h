#ifndef TEXT_h 
#define TEXT_h
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "point.h"
#include <string> 

/*! A test class */

class Text 
{
public: 
	Text(std::string const&, Point p, SDL_Renderer* r);
	~Text(); 
	void update();

private:
	std::string stext; /**< enum value 1 */
	Point position; /**< enum value 1 */
	SDL_Renderer* renderer; /**< enum value 1 */
};
#endif

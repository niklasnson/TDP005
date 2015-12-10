#ifndef TEXT_h 
#define TEXT_h
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "point.h"
#include <string> 

class Text 
{
public: 
	Text(std::string t, Point p);  

private:
	std::string out;
	Point position;
};
#endif

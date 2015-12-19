#ifndef TEXT_h 
#define TEXT_h
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "point.h"
#include <string> 

class Text 
{
public: 
	Text(std::string const&, Point p, SDL_Renderer* r);
	~Text(); 
	void update();

private:
	std::string stext;
	Point position;
	SDL_Renderer* renderer;
};
#endif

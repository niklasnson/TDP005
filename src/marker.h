#ifndef MARKER_h 
#define MARKER_h
#include "static.h"

class Marker : public Static 
{
public:
	Marker(std::string, Point, SDL_Renderer*, int, int, int);
	void update();
};
#endif

#ifndef MARKER_h 
#define MARKER_h
#include "sprite.h"

#include "static.h"

class Marker : public Static 
{
public:
	Marker(std::string, Point, SDL_Renderer*);
	void update();

private: 
	Sprite sprite;
};
#endif

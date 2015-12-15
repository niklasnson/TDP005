#ifndef SUPER_FRIENDLY_MISSILE_h 
#define SUPER_FRIENDLY_MISSILE_h
#include "friendly_missile.h"
#include "point.h"
#include "SDL2/SDL.h"
#include "marker.h"
#include "explosion.h"
#include <iostream> 
#include <string> 
#include <vector>
#include <map>

class Super_friendly_missile : public Friendly_missile 

{
public: 
	Super_friendly_missile(std::string,Point, SDL_Renderer*, 
		Point, int, std::map<int, std::vector<Game_object*>> &, 
		Marker*, bool*, int, int, int);
	void update(); 
	void explode(); 
};
#endif

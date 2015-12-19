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
	House(std::string const&, Point, SDL_Renderer*, int const&, int const&, int const&);
	void update(); 
	bool get_state() const; 
	void set_state(bool);

private: 
	bool intact;
};
#endif

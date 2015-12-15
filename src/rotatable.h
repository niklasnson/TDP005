#ifndef ROTATABLE_h
#define ROTATABLE_h
#include "point.h"
#include "game_object.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Rotatable : public Game_object 
{
public:
	Rotatable(std::string, 
						Point, 
						SDL_Renderer*, 
						Point, 
						int, 
						int, 
						int);
	void update() = 0;
	void calculate_allignment();
	Point get_target() const;
	void set_target(Point const& target);
	double get_angle(); 
	void set_angle(double const&); 

protected:
	Point target;
  double angle;	
};
#endif

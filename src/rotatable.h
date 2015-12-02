#ifndef ROTATABLE_h
#define ROTATABLE_h

#include "collisionable.h"
#include "point.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Rotatable : public Collisionable
{
	public:
	Rotatable(std::string, Point, SDL_Renderer*, Point);
	void update();
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

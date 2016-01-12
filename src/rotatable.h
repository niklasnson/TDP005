#ifndef ROTATABLE_h
#define ROTATABLE_h
#include "game_object.h"
#include "point.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Rotatable : public Game_object 
{
public:
  /*!
	 * Constructor for GameObject.
	 * @param filename, a string argument.
   * @param Point, a Point object.
   * @param renderer, a SDL_Renderer pointer.
   * @param Point, a Point object.
   * @param sprite_width, a int argument.
   * @param sprite_height, a int argument.
   * @param sprite_speed, a int argument. 
	 */
   Rotatable(std::string const&, Point, SDL_Renderer*, Point, 
	     int const&, int const&, int const&);
   void update() = 0;
   void calculate_allignment();
   Point get_target() const;
   void set_target(Point const& target);
   double get_angle() const; 
   void set_angle(double const&); 

protected:
   Point target;
   double angle;	
};
#endif

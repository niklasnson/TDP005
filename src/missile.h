#ifndef MISSILE_h
#define MISSILE_h

#include "variables.h"
#include "house.h"
#include "point.h"
#include "rotatable.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <random>
#include <string>
#include <vector>

class Missile : public Rotatable
{
public:
  /*!
	 * Constructor for Missile.
	 * @param filename, a string argument.
   * @param point, a Point object. 
   * @param renderer, a SDL_Renderer pointer.
   * @param target, a Point object. 
   * @param game_object, a Game_object vector.
   * @param sprite_width, a int argument.
   * @param sprite_height, a int argument.
   * @param sprite_speed, a int argument. 
	 */
	Missile(std::string const&, Point, SDL_Renderer*, Point, int, 
		std::map<int, std::vector<Game_object*>> &, int const&, int const&, int const&);
  
  /*!
	 * Constructor for Missile.
	 * @param filename, a string argument.
   * @param renderer, a SDL_Renderer pointer.
   * @param target, a Point object. 
   * @param game_object, a Game_object vector.
   * @param sprite_width, a int argument.
   * @param sprite_height, a int argument.
   * @param sprite_speed, a int argument. 
	 */
	Missile(std::string const&, SDL_Renderer*, int, 
		std::map<int, std::vector<Game_object*>> &, int const&, int const&, int const&);

	void move();
	void update() = 0;
	int get_speed() const;
	void set_speed(int const&);
	void set_move(double const&, double const&);
	void set_move(Point const&);
	bool get_state() const;
	void set_state(bool const&);
	Point get_random_target() const;
	Point get_random_spawn() const;

protected:
	int speed;
	bool is_missile;
	double curr_x;
	double curr_y;
	double move_x;
	double move_y;
	std::map<int, std::vector<Game_object*>> & m;
};

#endif

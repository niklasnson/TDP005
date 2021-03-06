#ifndef MISSILE_h
#define MISSILE_h

#include "variables.h"
#include "house.h"
#include "point.h"
#include "rotatable.h"
#include "texture.h"
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
	 * Constructor for Missile with set target.
   * @param textures - a Texture object.
	 * @param texture - a SDL_Texture pointer.
   * @param point - a Point object. 
   * @param renderer - a SDL_Renderer pointer.
   * @param target - a Point object.
   * @param speed - a int argument. 
   * @param game_objects - a Game_object map.
   * @param sprite_width - a int argument.
   * @param sprite_height - a int argument.
   * @param sprite_speed - a int argument. 
	 */
   Missile(Texture, SDL_Texture*, Point, SDL_Renderer*, Point, int, 
		std::map<int, std::vector<Game_object*>> &, int const&, int const&, int const&);
  
  /*!
	 * Constructor for Missile with random target.
   * @param textures - a Texture object.
   * @param texture - a SDL_Texture pointer.
   * @param renderer - a SDL_Renderer pointer.
   * @param speed - a int argument. 
   * @param game_objects - a Game_object map.
   * @param sprite_width - a int argument.
   * @param sprite_height - a int argument.
   * @param sprite_speed - a int argument. 
	 */
   Missile(Texture, SDL_Texture*, SDL_Renderer*, int, 
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
	Texture textures;  /**< Texture. */
  int speed;  /**< an int value. */
  bool is_missile;  /**< a bool value. */
	double curr_x;  /**< a double value. */
	double curr_y;  /**< a double value. */
	double move_x;  /**< a double value. */
	double move_y;  /**< a double value. */
	std::map<int, std::vector<Game_object*>> & m;   /**< a GameObject map. */
};

#endif

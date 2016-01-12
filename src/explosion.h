#ifndef EXPLOSION_h 
#define EXPLOSION_h 
#include "game_object.h"
#include "point.h"
#include "powerup.h"
#include "sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>
#include <vector>

class Explosion : public Game_object
{
public:
  /*!
	 * Constructor for Explosion.
	 * @param filename, a string argument.
   * @param point, a Pint object. 
   * @param renderer, a SDL_Renderer pointer.
   * @param game_object, a GameObject map. 
   * @param powerup, a bool argument. 
   * @param sprite_width, a int argument.
   * @param sprite_height, a int argument.
   * @param sprite_speed, a int argument. 
	 */
	Explosion(std::string const&, Point , SDL_Renderer*,
		std::map<int, std::vector<Game_object*>> &,bool*, int const&, int const&, int const&);
	void update(); 

protected:
	int timer;
	std::map<int, std::vector<Game_object*>> & m;
	bool* powerup;

};

#endif

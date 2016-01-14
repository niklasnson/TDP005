#ifndef POWERUP_h
#define POWERUP_h

#include "variables.h"
#include "missile.h"
#include "point.h"
#include "sprite.h"
#include "texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>
#include <vector>

class Powerup : public Missile
{
public:
  /*!
	 * Constructor for PowerupObject.
   * @param textures - a Texture object.
	 * @param texture - a SDL_Texture pointer.
   * @param renderer - a SDL_Renderer pointer.
   * @param speed - a int argument. 
   * @param game_objects - a vector argument. 
   * @param powerup - a Point object.
   * @param sprite_width - a int argument.
   * @param sprite_height - a int argument.
   * @param sprite_speed - a int argument. 
	 */
   Powerup(Texture, SDL_Texture*, SDL_Renderer*, int, 
		std::map<int, std::vector<Game_object*>> &, bool &, int const&, int const&, int const&);
	
  void update();
	
  void check_boundaries();
	
  Point get_random_target() const;

private:
	Point get_random_spawn() const;
};
#endif

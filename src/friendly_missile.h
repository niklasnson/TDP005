#ifndef FRIENDLY_MISSILE_h
#define FRIENDLY_MISSILE_h

#include "variables.h"
#include "explosion.h"
#include "game_object.h"
#include "marker.h"
#include "missile.h"
#include "point.h"
#include "sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>
#include <vector>
#include "texture.h"

class Friendly_missile : public Missile
{
public:
  /*!
	 * Constructor for FriendlyMissle.
   * @param textures - a Texture object.
	 * @param texture - a SDL_Texture pointer.
   * @param point - a Point object.
   * @param renderer - a SDL_Renderer pointer.
   * @param target - a Point object.
   * @param speed - a int argument. 
   * @param game_objects - a vector argument.
   * @param marker - a Marker object.
   * @param powerup - a bool argument. 
   * @param sprite_width - a int argument.
   * @param sprite_height - a int argument.
   * @param sprite_speed - a int argument. 
	 */  
   Friendly_missile(Texture, SDL_Texture*, Point, SDL_Renderer*, 
		Point, int, std::map<int, std::vector<Game_object*>> &, 
		Marker*, bool*, int const&, int const&, int const&);
	void update();
	void explode();
	void check_boundaries();
	bool reached_target(Point, Point); 

protected:
	Marker* marker; /**< a Marker pointer */
	bool* powerup; /**< a bool value. */
};

#endif



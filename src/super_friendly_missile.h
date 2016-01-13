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

/*! Missiles user fires when in power up mode. */
class Super_friendly_missile : public Friendly_missile 

{
public:
    /*!
	 * Constructor for SuperFriendlyMissile.
	 * @param text, a string argument.
	 * @param p, a Point object.
   * @param r, a SDL_Renderer pointer.
	 */

	/// Create a SuperFriendlyMissile
  Super_friendly_missile(SDL_Texture*, Point, SDL_Renderer*, 
		Point, int, std::map<int, std::vector<Game_object*>> &, 
		Marker*, bool*, int const&, int const&, int const&);
	/// Update object
  void update(); 
  /// Trigger the explosion
	void explode(); 
};
#endif

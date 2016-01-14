#ifndef SUPER_FRIENDLY_MISSILE_h 
#define SUPER_FRIENDLY_MISSILE_h
#include "friendly_missile.h"
#include "point.h"
#include "SDL2/SDL.h"
#include "marker.h"
#include "explosion.h"
#include "texture.h"
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
    * @param textures - a Texture object. 
    * @param texture - a Texture object.
    * @param point - a Point object.
    * @param renderer - a SDL_Renderer pointer.
    * @param target - a Point object.
    * @param speed - a int argument. 
    * @param game_objects - a GameObjects container .
    * @param marker - a Marker pointer.
    * @param powerup - a bool pointer. 
    * @param sprite_width - a int argument. 
    * @param sprite_height - a int argument. 
    * @param sprite_speed - a int argument.
    */

   /// Create a SuperFriendlyMissile
   Super_friendly_missile(Texture, SDL_Texture*, Point, SDL_Renderer*, 
			  Point, int, std::map<int, std::vector<Game_object*>> &, 
			  Marker*, bool*, int const&, int const&, int const&);
   /// Update object
   void update(); 
   /// Trigger the explosion
   void explode(); 

};
#endif

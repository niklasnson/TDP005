#ifndef ENEMYMISSILE_h
#define ENEMYMISSILE_h
#include "variables.h"
#include "explosion.h"
#include "house.h"
#include "missile.h"
#include "point.h"
#include "sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <map>
#include <string>
#include <vector>

class Enemy_missile : public Missile
{
public:
   /*!
    * Constructor for EnemyMissile.
    * @param texture - a SDL_Texture pointer.
    * @param renderer - a SDL_Renderer pointer. 
    * @param speed - a int argument. 
    * @param game_object - a GameObject map. 
    * @param sprite_width - a int argument.
    * @param sprite_height - a int argument.
    * @param sprite_speed - a int argument. 
    */
   Enemy_missile(SDL_Texture*, SDL_Renderer*, int, 
		 std::map<int, std::vector<Game_object*>> &, int const&, int const&, int const&); 

   void update();
   void check_boundaries();
   bool reached_target(Point const&, Point const&);
   void explode();
   bool get_hit_house() const;
   void set_hit_house(bool);
private:
   int timer;
   bool hit_house;
};
#endif

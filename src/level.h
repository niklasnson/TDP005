#ifndef LEVEL_h
#define LEVEL_h

#include "enemy_missile.h"
#include "texture.h"
#include "game.h"
#include "game_state.h"
#include "level.h"
#include "marker.h"
#include "player.h"
#include "powerup.h"
#include "super_friendly_missile.h"
#include <chrono>
#include <iomanip>
#include <map>
#include <random>
#include <sstream>
#include <vector>

class Level
{
public:
   /*!
    * Constructor for Level.
    * @param texture, a Texture object const-ref.
    * @param renderer, a SDL_Renderer pointer.
    * @param level, a int argument. 
    * @param lost, a bool argument. 
    * @param quit, a bool argument. 
    * @param score, a int value. 
    * @param speed, a int value. 
    * @param freq, a int value. 
    */
   Level(Texture, SDL_Renderer*, int const&, bool &, bool &, int &, int const&, int const&);
   void init();
   void run();
	
private:
   Texture texture;
   SDL_Renderer* renderer;
   int level;
   bool & lost;
   bool & quit;
   int & score;
   int const& fm_speed;
   int const& fm_frequency;
   int em_speed;
   int em_frequency;
   std::map<int, std::vector<Game_object*>> m;
   std::vector<Text*> t; 

};

#endif

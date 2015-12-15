#ifndef LEVEL_h
#define LEVEL_h

#include "enemy_missile.h"
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
		Level(SDL_Renderer*, int, bool &, bool &, int &, int &, int &);
		void init();
		void run();
	
	private:
		SDL_Renderer* renderer;
		int level;
		bool & lost;
		bool & quit;
		int & score;
		int & fm_speed;
		int & fm_frequency;
		int em_speed;
		int em_frequency;
		std::map<int, std::vector<Game_object*>> m;
		std::vector<Text*> t; 

};

#endif

#include "game.h"
#include <vector>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "static.h"
#include "screen_dimensions.h"
#include "rotatable.h"
#include "point.h"
#include "player.h"
#include "missile.h"
#include "house.h"
#include "game_object.h"
#include "friendly_missile.h"
#include "enemy_missile.h"
#include "collisionable.h"
#include "aabb.h"
#include "marker.h"
#include "game_state.h"
#include "game.h"
#include "level.h"
#include "start.h"

#include <map>
#include <random>
#include <chrono>
#include "powerup.h"

using namespace std;

Game::Game(SDL_Renderer* r, int l):Game_state(r, l)
{
	init();
}

void Game::init()
{
	bool lost{false};
	bool quit{false};
	int score{0};
	int fm_speed{4};
	int fm_frequency{500};
	while(!lost && !quit)
	{
		Level gamelevel{renderer, get_level(), lost, quit, score, fm_speed, fm_frequency};
		if (!lost)
		{
			level = level + 1;
			Start s{renderer, 1}; //will be intermission/levelup screen
		}
	}
}

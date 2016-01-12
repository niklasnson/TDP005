#ifndef GAME_STATE_h
#define GAME_STATE_h

#include <map>
#include <random>
#include <chrono>
#include <vector>
#include <iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>


class Game_state
{
public:
  /*!
	 * Constructor for GameState.
   * @param renderer, a SDL_Renderer pointer.
   * @param quit, a bool argument. 
	 */
	Game_state(SDL_Renderer*, int, bool &);
	virtual ~Game_state();
	void set_level(int const&);
	int get_level() const;

protected:
	SDL_Renderer* renderer;
	int level;
	bool & quit;
};

#endif

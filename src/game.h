#ifndef GAME_h
#define GAME_h

#include "game_state.h"
#include "game_object.h"
#include "text.h"
#include "level.h"
#include "start.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

class Game: public Game_state
{
public:
	Game(SDL_Renderer*, int, int &, bool &);
	void init();
	void Powerup_screen(int&, int&, bool&);
	void End_screen(int const& score); 

private:
	std::map<int, std::vector<Game_object*>> m;
	std::vector<Text*> t; 
	int & score;
};
#endif


#include <iostream>
#include "game_state.h"

using namespace std;

Gamestate::Gamestate():{}

void Gamestate::set_renderer(SDL_RENDERER* ren)
{
	renderer = ren;
}

SDL_RENDERER* Gamestate::get_renderer()
{
	return renderer;
}

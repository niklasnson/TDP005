#include "game_state.h"

using namespace std;

Game_state::Game_state(SDL_Renderer* r, int l, bool & quit):renderer{r}, level{l}, quit{quit}{}

Game_state::~Game_state(){}

void Game_state::set_level(int i)
{
	level = i;
}

int Game_state::get_level()
{
	return level;
}

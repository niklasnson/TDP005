#include "game_state.h"

using namespace std;

Game_state::Game_state(SDL_Renderer* r, int l, bool & quit):renderer{r}, level{l}, quit{quit}{}

Game_state::~Game_state(){}

/// Set the current level. 
void Game_state::set_level(int const& i)
{
	level = i;
}

/// Get the current level. 
int Game_state::get_level() const
{
	return level;
}

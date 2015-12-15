#ifndef ENDGAME_h
#define ENDGAME_h
#include "game_state.h"
#include "house.h"
#include "text.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <map>
#include <sstream>

class Endgame : public Game_state
{
	public:
		Endgame(SDL_Renderer*, int, int &, bool &);
		void init();
		std::vector<std::pair<int, std::string>> load_highscore();
		std::string player_input();
		void show_highscore(std::vector<std::pair<int, std::string>> &);
		void update_file(std::vector<std::pair<int, std::string>>);
	private:
		std::map<int, std::vector<Game_object*>> m;
		std::vector<Text*> t;
		int & score;

};
#endif

#ifndef ENDGAME_h
#define ENDGAME_h
#include "text.h"
#include "game_state.h"
#include "game_object.h"

class Endgame : public Game_state
{
	public:
		Endgame(SDL_Renderer*, int, int &);
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

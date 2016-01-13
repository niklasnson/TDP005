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
#include "texture.h"

class Endgame : public Game_state
{
public:
  /*!
	 * Constructor for Endgame.
   * @param renderer - a SDL_Renderer pointer.
   * @param level - a int argument. 
   * @param score - a int argument. 
   * @param quit - a bool argument.
   * @param texture - a Texture object.
	 */
   Endgame(SDL_Renderer*, int const&, int &, bool &, Texture);
   void init();
   std::vector<std::pair<int, std::string>> load_highscore() const;
   std::string player_input();
   void show_highscore(std::vector<std::pair<int, std::string>> &);
   void update_file(std::vector<std::pair<int, std::string>>) const;
private:
   std::map<int, std::vector<Game_object*>> m;
   std::vector<Text*> t;
   int & score;

};
#endif

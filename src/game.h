#ifndef GAME_h
#define GAME_h

#include "game_state.h"
#include "game_object.h"
#include "text.h"
#include "level.h"
#include "start.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "texture.h"

class Game: public Game_state
{
public:
   /*!
    * Constructor for Game.
    * @param renderer, a SDL_Renderer pointer.
    * @param level, a int argument.
    * @param score, a int argument.
    * @param quit, a bool argument. 
    */  
   Game(SDL_Renderer*, int, int &, bool &, Texture);
   void init();
   void Powerup_screen(int&, int&, bool&);
   void End_screen(int const& score); 

private:
   std::map<int, std::vector<Game_object*>> m;
   std::vector<Text*> t; 
   int & score;
};
#endif


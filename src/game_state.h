#ifndef GAME_STATE_h
#define GAME_STATE_h

#include "texture.h"
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
    * @param renderer - a SDL_Renderer pointer.
    * @param quit - a bool argument. 
    * @param texture - a Texture object.
    */
   Game_state(SDL_Renderer*, int, bool &, Texture);
   virtual ~Game_state();
   void set_level(int const&);
   int get_level() const;

protected:
   SDL_Renderer* renderer; /*!< an SDL_Renderer* pointer */
   int level; /*!< an integer value */
   bool & quit; /*!< an bool value */
   Texture texture; /*!< an Texture object */
};

#endif

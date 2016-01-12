#include "variables.h"
#include "endgame.h"
#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Main_game
{
public:
   Main_game();
   ~Main_game();
   void run();

private:
   int score;
   bool quit;
   SDL_Renderer* renderer;
   SDL_Window* window;
   SDL_Texture* cursor;
};

#include "main_game.h"

using namespace std;

Main_game::Main_game():score{0}, quit{false}, renderer{NULL}, window{NULL}, cursor{NULL}
{
   //initialize SDL
   window = SDL_CreateWindow( "KOMRAD KOMMAND", SDL_WINDOWPOS_UNDEFINED, 
			      SDL_WINDOWPOS_UNDEFINED, Variables::screen_width, 
			      Variables::screen_height, SDL_WINDOW_SHOWN);
   renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
   SDL_SetRenderDrawColor(renderer, 255, 255, 226, 0);
		
   if(TTF_Init()==-1) 
   {
      std::cout << "TTF_Init: error!" << std::endl;
      exit(2);
   }
	
   //Cursor made
   SDL_Surface* loaded_surface = IMG_Load("sprites/aim.png");
   cursor = SDL_CreateTextureFromSurface(renderer, loaded_surface);
   SDL_FreeSurface(loaded_surface);
   SDL_ShowCursor(0);
   SDL_Rect cursor_hitbox;
   SDL_QueryTexture(cursor, NULL, NULL, &cursor_hitbox.w, &cursor_hitbox.h);
   if (cursor == nullptr)
      std::cout << "FAILEDTOLOAD" << std::endl;


}

Main_game::~Main_game()
{
   //SDL cleanup
   SDL_DestroyTexture(cursor);
   TTF_Quit();
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
}

void Main_game::run()
{
   //create all textures
   Texture texture{renderer};
   
   //run game
   Start s{renderer, 1, quit, texture}; 
   Game g{renderer, 1, score, quit, texture};
   Endgame e{renderer, 1, score, quit, texture};
   
   texture release_textures();
}

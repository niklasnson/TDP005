#include "start.h"

Start::Start(SDL_Renderer* renderer, int level, bool & quit, Texture texture):Game_state(renderer, level, quit, texture)
{
   init();
}

void Start::init()
{
   //mouse stuff
   SDL_Texture* cursor;
   //SDL_Surface* loaded_surface = IMG_Load("sprites/aim.png");
   //cursor = SDL_CreateTextureFromSurface(renderer, loaded_surface);
   cursor = texture.get_texture("sprites/aim.png");
   //SDL_FreeSurface(loaded_surface);
   SDL_Rect cursor_hitbox;
   SDL_QueryTexture(cursor, NULL, NULL, &cursor_hitbox.w, &cursor_hitbox.h);
   if (cursor == nullptr)
   {
      std::cout << "FAILED TO LOAD cursor" << std::endl;
      SDL_ShowCursor(0);
   }
	
   SDL_Event e;
   bool end{false};

   //yeah its a house object used to print the main menu on screen
   m[1].push_back(new House{texture.get_texture("sprites/scaledmenu.png"), Point{0, 0}, renderer, 1140, 800, 1});

   while(!end && !quit)
   {
      SDL_RenderClear(renderer);

      while( SDL_PollEvent( &e ) != 0 )
      {
	 if( e.type == SDL_QUIT )
	 {
	    quit = true;
	 }
	 if(e.type == SDL_MOUSEBUTTONUP)
	 {
	    end = true;
	 }
      }
      for(std::pair<const int, std::vector<Game_object*>>& a : m)
      {
	 for(std::vector<Game_object*>::iterator it{a.second.begin()}; it != a.second.end();)
	 {
	    (*it) -> update();
	    ++it;
	 }
      }
      SDL_GetMouseState(&cursor_hitbox.x, &cursor_hitbox.y);
      cursor_hitbox.x += 2;
      cursor_hitbox.y += 2;
      SDL_RenderCopy(renderer, cursor, NULL, &cursor_hitbox);

      SDL_RenderPresent(renderer);
      SDL_Delay(10);
   }
   //cleanup
   SDL_DestroyTexture(cursor);
   for(std::pair<const int, std::vector<Game_object*>>& a : m)
   {
      for(std::vector<Game_object*>::iterator it{a.second.begin()}; it != a.second.end();)
      {
	 Game_object* todel = *it;
	 it = a.second.erase(it);
	 delete todel;
      }
   }

}

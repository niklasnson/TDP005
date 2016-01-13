#include "texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

SDL_Texture* new_texture(std::string const& f, SDL_Renderer* const& r)
{
   SDL_Surface* loaded_surface = IMG_Load(f.c_str());
   SDL_Texture* new_texture; 
   new_texture = SDL_CreateTextureFromSurface(r, loaded_surface);
   SDL_FreeSurface(loaded_surface);
   return new_texture;
}

Texture::Texture(SDL_Renderer* renderer):renderer{renderer}
{
   pointers.emplace("sprites/medal.png", new_texture("sprites/medal.png", renderer));
   pointers.emplace("sprites/house_hi_d.png", new_texture("sprites/house_hi_d.png", renderer));
   pointers.emplace("sprites/scaledgexplosion.png", new_texture("sprites/scaledgexplosion.png", renderer));
   pointers.emplace("sprites/explosion.png", new_texture("sprites/explosion.png", renderer));
   pointers.emplace("sprites/box.png", new_texture("sprites/box.png", renderer));
   pointers.emplace("sprites/fodder.png", new_texture("sprites/fodder.png", renderer));
   pointers.emplace("sprites/house_hi.png", new_texture("sprites/house_hi.png", renderer));
   pointers.emplace("sprites/armytruck.png", new_texture("sprites/armytruck.png", renderer));
   pointers.emplace("sprites/enemy2.png", new_texture("sprites/enemy2.png", renderer));
   pointers.emplace("sprites/powerup.png", new_texture("sprites/powerup.png", renderer));
   pointers.emplace("sprites/marker.png", new_texture("sprites/marker.png", renderer));
   pointers.emplace("sprites/player.png", new_texture("sprites/player.png", renderer));
   pointers.emplace("sprites/playerp.png", new_texture("sprites/playerp.png", renderer));
   pointers.emplace("sprites/aim.png", new_texture("sprites/aim.png", renderer));
   pointers.emplace("sprites/scaledmenu.png", new_texture("sprites/scaledmenu.png", renderer));
}

Texture::~Texture()
{
   //textures are deleted manually with the public function release_textures below
}

SDL_Texture* Texture::get_texture(string name)
{
   return pointers[name];
}

void Texture::release_textures()
{
   // for (pair<string, SDL_Texture*> p : pointers)
   // {
      
   // }

   for(std::map<std::string, SDL_Texture*>::iterator it{pointers.begin()}; it != pointers.end();)
   {
      SDL_Texture* todel = (*it).second;
      it = pointers.erase(it);
      SDL_DestroyTexture(todel);
   }

}

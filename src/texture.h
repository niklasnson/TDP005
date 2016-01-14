#ifndef TEXTURE_h
#define TEXTURE_h

#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

class Texture
{
public:
  /*!
   * Constructor for Texture.
   * @param renderer - a SDL_Renderer pointer.
  */
   Texture(SDL_Renderer*);
   ~Texture();
   SDL_Texture* get_texture(std::string);
   void release_textures();
	
private:
   SDL_Renderer* renderer;
   std::map<std::string, SDL_Texture*> pointers;

};

#endif

#ifndef STATIC_H 
#define STATIC_H 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "point.h"
#include "game_object.h"

/*! Objects that not move  */
class Static : public Game_object
{
public:
  /// Create a StaticObject
	Static(std::string const&, Point, SDL_Renderer*, int const&, int const&, int const&);
	/// Update object
  void update(); 
}; 
#endif 

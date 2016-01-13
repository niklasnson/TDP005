#ifndef SPRITE_h
#define SPRITE_h
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "point.h"
#include <string>
#include <iostream>

class Sprite
{
public:

   /*!
    * Constructor for Sprite.
    * @param texture, a pointer to SDL_Texture.
    * @param renderer, a SDL_Renderer pointer.
    * @param sprite_width, a int argument.
    * @param sprite_height, a int argument.
    * @param sprite_speed, a int argument. 
    */
   Sprite(SDL_Texture*, SDL_Renderer*, int const&, int const&, int const&);
	
   /// Destructor for Sprite
   ~Sprite();

   /// Returns the frame with.
   int get_frame_width() const;
  
   /// Returns the frame height. 
   int get_frame_height() const; 
  
   /// Draw Sprite.
   void draw(Point const&);
  
   /// Draw Sprite with an angle. 
   void draw(Point const&, double const&);
private: 
   SDL_Renderer* renderer;
   int frame_width;
   int frame_height; 
   int animation_speed;
   int image_width; 
   int image_height;
   bool is_destroyed; 
   int animation_is_at; 
   SDL_Texture* image;
   bool is_animated; 
   int animation_length;
   int animation_counter; 
};
#endif

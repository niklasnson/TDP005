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
	Sprite(std::string, Point, SDL_Renderer*, int, int, int);
	int get_frame_width();
	void draw(); 
private: 
	Point cords;
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

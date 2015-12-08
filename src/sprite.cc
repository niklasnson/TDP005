#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "point.h"
#include <iostream>
#include "sprite.h"
#include <string>

SDL_Texture* make_texture(std::string f, SDL_Renderer* r)
{
	SDL_Surface* loaded_surface = IMG_Load(f.c_str());
	SDL_Texture* new_texture; 
	new_texture = SDL_CreateTextureFromSurface(r, loaded_surface);
	SDL_FreeSurface(loaded_surface);
	return new_texture;
}

Sprite::Sprite(std::string img, SDL_Renderer* r, int w, int h, int s):
		renderer{r},
		frame_width{w}, 
		frame_height{h}, 
		animation_speed{s}, 
		image_width{0},
		image_height{0},
		is_destroyed{false},
		animation_is_at{1},
		animation_counter{0}
{
	image = make_texture(img, renderer);
	SDL_QueryTexture(image, NULL, NULL, &image_width, &image_height); 
	animation_length = (image_width / frame_width);
	if (animation_speed != 0) 
	{
		is_animated = true;	
	}
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(image);
	//std::cout << "NULL SET" << std::endl;
	image = nullptr;
}

void Sprite::draw(Point cords)
{
	draw(cords, 0); 
}

void Sprite::draw(Point cords, double angle=0) 
{
	if (is_animated)
	{
		SDL_Rect srect{ animation_is_at * frame_width, 0, frame_width, frame_height };
		SDL_Rect dst{cords.x, cords.y, frame_width, frame_height};
		SDL_RenderCopyEx(renderer, image, &srect, &dst, angle, NULL, SDL_FLIP_NONE);
		animation_counter += 1; 
		if (animation_counter % animation_speed == 0)
		{
			animation_is_at += 1; 
		}
		if (animation_is_at == animation_length) 
		{
			animation_is_at = 1; 
		}
	}
	else 
	{
		SDL_Rect dst{cords.x, cords.y, image_width, image_height};
		SDL_RenderCopy(renderer, image, NULL, &dst);
	}
}

int Sprite::get_frame_width()
{
	return frame_width;
}

int Sprite::get_frame_height()
{
	return frame_height;
}

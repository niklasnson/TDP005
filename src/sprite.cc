#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "point.h"
#include <iostream>
#include "sprite.h"
#include <string>
#include <sstream>

SDL_Texture* make_texture(std::string const& f, SDL_Renderer* const& r)
{
	SDL_Surface* loaded_surface = IMG_Load(f.c_str());
	SDL_Texture* new_texture; 
	new_texture = SDL_CreateTextureFromSurface(r, loaded_surface);
	SDL_FreeSurface(loaded_surface);
	return new_texture;
}

Sprite::Sprite(std::string const& file_name,
		SDL_Renderer* renderer,
		int const& sprite_width,
		int const& sprite_height,
		int const& sprite_speed):
			renderer{renderer},
			frame_width{sprite_width}, 
			frame_height{sprite_height}, 
			animation_speed{sprite_speed}, 
			image_width{0},
			image_height{0},
			is_destroyed{false},
			animation_is_at{1},
			animation_counter{0}
{
	image = make_texture(file_name, renderer);
	SDL_QueryTexture(image, NULL, NULL, &image_width, &image_height); 
	animation_length = (image_width / frame_width);
	if (animation_speed != 0) 
	{
		is_animated = true;	
	}
	else 
	{
		is_animated = false;
	}
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(image);
	image = nullptr;
}

/// Objects that does not rotate calls other draw with 0 degrees rotation.
void Sprite::draw(Point const& cords)
{
	draw(cords, 0); 
}

/// Objects are drawn with rotation.
void Sprite::draw(Point const& cords, double const& angle) 
{
	SDL_Rect srect{ animation_is_at * frame_width, 0, frame_width, frame_height };
	SDL_Rect dst{cords.x, cords.y, frame_width, frame_height};
	if (is_animated)
	{
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
		SDL_RenderCopyEx(renderer, image, NULL, &dst, angle, NULL, SDL_FLIP_NONE);
	}
}

int Sprite::get_frame_width() const
{
	return frame_width;
}

int Sprite::get_frame_height() const
{
	return frame_height;
}

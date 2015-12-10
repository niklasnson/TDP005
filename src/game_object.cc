#include "game_object.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "point.h"
#include <iostream>
#include "sprite.h"

SDL_Texture* create_texture(std::string f, SDL_Renderer* r)
{
	SDL_Surface* loaded_surface = IMG_Load(f.c_str());
	SDL_Texture* new_texture; 
	new_texture = SDL_CreateTextureFromSurface(r, loaded_surface);
	SDL_FreeSurface(loaded_surface);
	return new_texture;
}

// [new code]
Game_object::Game_object(std::string i, Point p, SDL_Renderer* r, int sW, int sH, int sS): cords{p.x, p.y}, renderer{r}, destroyed{false}, sprite{i, r, sW, sH, sS}{}
// [/new code]

Game_object::~Game_object()
{}

// [new code]
void Game_object::draw(double angle)
{
	sprite.draw(get_point(), angle); 
}

void Game_object::draw()
{ 
	sprite.draw(get_point()); 
}
// [/new code]


void Game_object::set_point(Point p)
{
	cords = p;
}

Point Game_object::get_point()
{
	return cords;
}

void Game_object::set_image(std::string f)
{
	image = create_texture(f, renderer);
}

SDL_Texture* Game_object::get_image()
{
	return image;
}

void Game_object::set_renderer(SDL_Renderer* r)
{
	renderer = r;
}

SDL_Renderer* Game_object::get_renderer()
{
	return renderer;
}

bool Game_object::is_destroyed()
{
	return destroyed;
}

void Game_object::release_texture()
{
	SDL_DestroyTexture(image);
	//std::cout << "NULL SET" << std::endl;
	image = nullptr;
}

void Game_object::destroy()
{
	destroyed = true;
}


#include "game_object.h"

SDL_Texture* create_texture(std::string f, SDL_Renderer* r)
{
	SDL_Surface* loaded_surface = IMG_Load(f.c_str());
	SDL_Texture* new_texture; 
	new_texture = SDL_CreateTextureFromSurface(r, loaded_surface);
	SDL_FreeSurface(loaded_surface);
	return new_texture;
}

Game_object::Game_object(
	std::string filename, 
	Point point, 
	SDL_Renderer* renderer,
	int sprite_width, 
	int sprite_height, 
	int sprite_speed):cords{point.x, point.y}, renderer{renderer}, destroyed{false}, 
		sprite{filename, renderer, sprite_width, sprite_height, sprite_speed}
{}

Game_object::~Game_object()
{}

void Game_object::draw(double angle)
{
	sprite.draw(get_point(), angle); 
}

void Game_object::draw()
{ 
	sprite.draw(get_point()); 
}

void Game_object::set_point(Point p)
{
	cords = p;
}

Point Game_object::get_point()
{
	return cords;
}

void Game_object::set_image(std::string filename)
{
	image = create_texture(filename, renderer);
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
	image = nullptr;
}

void Game_object::destroy()
{
	destroyed = true;
}


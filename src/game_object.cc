#include "game_object.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "point.h"

SDL_Texture* create_texture(std::string f, SDL_Renderer* r)
{
	SDL_Surface* loaded_surface = IMG_Load(f.c_str());
	SDL_Texture* new_texture; 
	new_texture = SDL_CreateTextureFromSurface(r, loaded_surface);
	SDL_FreeSurface(loaded_surface);
	return new_texture;
}

Game_object::Game_object(std::string i, Point crd, SDL_Renderer* r):img{i}, cords{crd.x, crd.y}, renderer{r}
{
	image = create_texture(img, renderer);
}

void Game_object::draw()
{
	SDL_RenderCopy(renderer, image, NULL, NULL);
}

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


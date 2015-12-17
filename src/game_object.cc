#include "game_object.h"

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

//draws object that needs to rotate
void Game_object::draw(double angle)
{
	sprite.draw(get_point(), angle); 
}

//draws objects that does not rotate
void Game_object::draw()
{ 
	sprite.draw(get_point()); 
}

//point is the coordinate the object is at
void Game_object::set_point(Point p)
{
	cords = p;
}

Point Game_object::get_point()
{
	return cords;
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

//destoryed is a bool,
//decides if object need to be removed during gameloop
void Game_object::destroy()
{
	destroyed = true;
}


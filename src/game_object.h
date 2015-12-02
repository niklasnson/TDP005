#ifndef GAME_OBJECT_h 
#define GAME_OBJECT_h
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "point.h"
#include <string>

class Game_object 
{
public: 
	Game_object(std::string, Point, SDL_Renderer*);
	//virtual void update() = 0;
	void draw(); 
	void set_point(Point);
	Point get_point(); 
	void set_image(std::string);
	SDL_Texture* get_image(); 
	void set_renderer(SDL_Renderer*); 
	SDL_Renderer* get_renderer(); 

protected: 
	std::string img;
	Point cords;
	SDL_Texture* image; 
	SDL_Renderer* renderer;
};
#endif



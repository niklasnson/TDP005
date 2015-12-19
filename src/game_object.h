#ifndef GAME_OBJECT_h 
#define GAME_OBJECT_h
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "point.h"
#include <string>
#include "sprite.h"

class Game_object 
{
public:
	Game_object(std::string const&, Point, SDL_Renderer*, int const&, int const&, int const&);
	virtual ~Game_object();
	virtual void update() = 0;
	void draw(double const&);
	void draw();
	void set_point(Point const&);
	Point get_point() const; 
	void set_renderer(SDL_Renderer*); 
	SDL_Renderer* get_renderer() const;
	bool is_destroyed() const;
	void destroy();

protected: 
	std::string img;
	Point cords;
	SDL_Renderer* renderer;
	bool destroyed;
	Sprite sprite; 
};
#endif

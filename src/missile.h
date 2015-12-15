#ifndef MISSILE_h
#define MISSILE_h

#include "house.h"
#include "point.h"
#include "rotatable.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <random>
#include <string>
#include <vector>

class Missile : public Rotatable
{
public:
	Missile(std::string, Point, SDL_Renderer*, Point, int, 
		std::map<int, std::vector<Game_object*>> &, int, int, int);

	Missile(std::string, SDL_Renderer*, int, 
		std::map<int, std::vector<Game_object*>> &, int, int, int);

	void move();
	void update() = 0;
	int get_speed();
	void set_speed(int const&);
	void set_move(double, double);
	void set_move(Point);
	bool get_state();
	void set_state(bool);
	Point get_random_target();
	Point get_random_spawn();

protected:
	int speed;
	bool is_missile;
	double curr_x;
	double curr_y;
	double move_x;
	double move_y;
	std::map<int, std::vector<Game_object*>> & m;
};

#endif

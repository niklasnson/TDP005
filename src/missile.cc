
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <iostream>
#include <map>
#include <random>
#include <vector>

#include "point.h"
#include "house.h"
#include "aabb.h"
#include "missile.h"

using namespace std;

Missile::Missile(std::string f,
		Point p,
		SDL_Renderer* r,
		Point t,
		int s,
		map<int, vector<Game_object*>> &m):
	Rotatable(f, p, r, t),
	speed{s},
	is_missile{true},
	curr_x{static_cast<double>(get_point().x)},
	curr_y{static_cast<double>(get_point().y)},
	move_x{0},
	move_y{0},
	m(m)
{
	set_target(get_random_target());
	calculate_allignment();
	double delta_x{static_cast<double>(target.x-cords.x)};
	double delta_y{static_cast<double>(target.y-cords.y)};
	double greatest_delta{abs(delta_y)};


	if (abs(delta_x) > abs(delta_y))
		greatest_delta = abs(delta_x);
	
	set_move(delta_x/greatest_delta, delta_y/greatest_delta);
//	move_x = delta_x/greatest_delta;
//	move_y = delta_y/greatest_delta;
}
/*
Missile::Missile(
		std::string f,
		Point p,
		SDL_Renderer* r,
		int s,
		map<int, vector<Game_object*>> &m):
	Missile(f,p,r,get_random_target(),s,m){}
	
*/
void Missile::move()
{
	curr_x += (move_x * speed);
	curr_y += (move_y * speed);
	//cout << "x: " << move_x << "  y: " << move_y << endl;
	Point new_location{static_cast<int>(curr_x + 0.5), static_cast<int>(curr_y + 0.5)};
	set_point(new_location);

}

void Missile::update()
{	
	move();
	draw(angle);
	//do everyting that needs to be done to update, think simulate
}

int Missile::get_speed()
{
	return speed;
}

void Missile::set_speed(int const& spd)
{
	speed = spd;
}

void Missile::set_move(double x, double y)
{
	move_x = x;
	move_y = y;
}

void Missile::set_move(Point a)
{
	move_x = a.x;
	move_y = a.y;
}

bool Missile::get_state()
{
		return is_missile;
}

void Missile::set_state(bool st)
{
	is_missile = st;
}

Point Missile::get_random_target()
{
	bool done{false};
	Point target;

	while (!done)
	{

		std::random_device rd;
		std::mt19937 gen(rd());

		std::uniform_int_distribution<int> dis(0, 5);

//	cout << "hej" << endl;
//  cout << m.size();
//	cout << "efter tmp" << endl;
		if(dynamic_cast<House*>(m[1].at(dis(gen))) -> get_state())
		{
			cout << target.x << " "<< target.y << endl;
			target.x = m[1].at(dis(gen)) -> get_point().x; //16 half house width
			target.y = m[1].at(dis(gen)) -> get_point().y; //16 half house width
			done=true;
			cout << target.x << " "<< target.y << endl;
		}
	
	}
	target.x += 16;
	return target;

	/*Screen_dimensions sd;
	std::random_device rd;
	std::mt19937 gen(rd());
	int x;
	int y;
	std::uniform_int_distribution<int> dis(1, sd.SCREEN_W);
	
	x = dis(gen);
	y = 1130;

	Point targ{x, y};
	return targ;*/
}


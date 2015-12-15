#include "missile.h"
Missile::Missile(
	std::string filename, 
	Point point,
	SDL_Renderer* renderer, 
	Point target,
	int speed, 
	std::map<int, std::vector<Game_object*>> &game_objects, 
	int sprite_width, 
	int sprite_height, 
	int sprite_speed):Rotatable(filename, point, renderer, 
		target, sprite_width, sprite_height, sprite_speed),
	speed{speed},
	is_missile{true},
	curr_x{static_cast<double>(get_point().x)},
	curr_y{static_cast<double>(get_point().y)},
	move_x{0},
	move_y{0},
	m(game_objects)
{
	calculate_allignment();
	double delta_x{static_cast<double>(target.x-cords.x)};
	double delta_y{static_cast<double>(target.y-cords.y)};
	double greatest_delta{std::abs(delta_y)};
	if (abs(delta_x) > abs(delta_y))
		greatest_delta = abs(delta_x);
	set_move(delta_x/greatest_delta, delta_y/greatest_delta);
}

Missile::Missile(
	std::string filename, 
	SDL_Renderer* renderer, 
	int speed, 
	std::map<int, std::vector<Game_object*>> &game_objects, 
	int sprite_width, 
	int sprite_height, 
	int sprite_speed):Rotatable(filename, get_random_spawn(), 
		renderer, Point{0,0}, sprite_width, sprite_height, sprite_speed),
	speed{speed}, 
	is_missile{true},
	curr_x{static_cast<double>(get_point().x)},
	curr_y{static_cast<double>(get_point().y)},
	move_x{0},
	move_y{0},
	m(game_objects)
{
	set_target(get_random_target());
	calculate_allignment();
	double delta_x{static_cast<double>(target.x-cords.x)};
	double delta_y{static_cast<double>(target.y-cords.y)};
	double greatest_delta{std::abs(delta_y)};
	if (abs(delta_x) > abs(delta_y))
		greatest_delta = abs(delta_x);
	set_move(delta_x/greatest_delta, delta_y/greatest_delta);
}

Point Missile::get_random_target()
{
	bool done{false};
	Point target;

	while (!done)
	{
		done=false;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, 5);
			if(dynamic_cast<House*>(m[1].at(dis(rd))) -> get_state())
		{
			target.x = m[1].at(dis(gen)) -> get_point().x; //16 half house width
			target.y = m[1].at(dis(gen)) -> get_point().y; //16 half house width
			done=true;
		}
	}
	target.x += 16;
	return target;
}

Point Missile::get_random_spawn()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	int x;
	int y;
	std::uniform_int_distribution<int> dis(1, 1130);
	
	x = dis(gen);
	y = 1;

	Point p{x, y};
	return p;
}

void Missile::move()
{
	curr_x += (move_x * speed);
	curr_y += (move_y * speed);
	Point new_location{static_cast<int>(curr_x + 0.5), static_cast<int>(curr_y + 0.5)};
	set_point(new_location);

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


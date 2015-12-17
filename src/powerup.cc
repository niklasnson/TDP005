#include "powerup.h"
Powerup::Powerup(
		std::string filename,
		SDL_Renderer* renderer,
		int speed,
		std::map<int, std::vector<Game_object*>> & game_objects, 
		bool & powerup, 
		int sprite_width, 
		int sprite_height, 
		int sprite_speed):Missile(filename, get_random_spawn(),
			renderer, get_random_target(),speed, game_objects, sprite_width,
			sprite_height, sprite_speed)
{}

void Powerup::update()
{
	if (get_state())
	{
		move();
		check_boundaries();
		draw(angle);
	}
}

//check if outside screen
void Powerup::check_boundaries()
{
	if (get_point().y > 800 || 
			get_point().y < 0 || 
			get_point().x > 1130 || 
			get_point().x <0)
		{destroy();}
}

Point Powerup::get_random_spawn()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	int x;
	int y;
	std::uniform_int_distribution<int> dis(100, 1000);
	
	x = dis(gen);
	y = 1;

	Point p{x, y};
	return p;
}

Point Powerup::get_random_target()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	int x;
	int y;
	std::uniform_int_distribution<int> dis(100, 1000);
	
	x = dis(gen);
	y = 800;

	Point p{x, y};
	return p;
}


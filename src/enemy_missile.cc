#include "enemy_missile.h"

Enemy_missile::Enemy_missile(
	std::string filename, 
	SDL_Renderer* renderer, 
	int speed, 
	std::map<int, std::vector<Game_object*>> & game_objects, 
	int sprite_width, 
	int sprite_height, 
	int sprite_speed): Missile(filename, renderer, speed, 
		game_objects, sprite_width, sprite_height, sprite_speed),
	timer{0}, 
	hit_house{false}
{}

//Update moves missile, checks if it hit or went of screen.
void Enemy_missile::update()
{
	if (get_state())
	{
		move();
		check_boundaries();
		draw(get_angle());
		if(reached_target(get_point(), get_target()))
		{
			set_hit_house(true);
			explode();
		}
	}
}
//check if missile is off the screen
void Enemy_missile::check_boundaries()
{
	if (get_point().y > Variables::screen_height || 
			get_point().y < 0 || 
			get_point().x > Variables::screen_width || 
			get_point().x < 0)
		{
			destroy();
		}
}
//se if missile reached assigned house
bool Enemy_missile::reached_target(Point a, Point b)
{
	return b.x-2 <= a.x+2 && b.x+2 >= a.x-2 
				&& b.y-2 <= a.y+2 && b.y+2 >= a.y-2;
}

//destroys the house house it hit
void Enemy_missile::explode()
{
	Point housepos{0, 0};
	for (auto go : m[1])
	{
		if (go -> get_point().x <= (get_point().x)+60 && (go -> get_point().x)+60 >= get_point().x 
         && go->get_point().y <= (get_point().y)+10 && (go->get_point().y)+10 >= get_point().y)
		{
			housepos.x = go->get_point().x;
			housepos.y = go->get_point().y;
			dynamic_cast<House*>(go) -> destroy();
		}
	}
	House* newhouse{new House{"sprites/house_hi_d.png", housepos, renderer, 96, 96, 10}};
	newhouse -> set_state(false);
	m[1].push_back(newhouse);

	set_state(false);
	set_speed(0);
	set_move(0, 0);
	Point explosion_point{get_point().x - 70, get_point().y - 44};
	bool powerup;
	m[5].push_back(new Explosion{"sprites/scaledgexplosion.png", explosion_point, get_renderer(), m, &powerup, 185, 222, 8});
	destroy();
}

bool Enemy_missile::get_hit_house()
{
	return hit_house;
}

void Enemy_missile::set_hit_house(bool a)
{
	hit_house = a;
}

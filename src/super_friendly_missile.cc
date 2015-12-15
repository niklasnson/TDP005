#include "super_friendly_missile.h" 

Super_friendly_missile::Super_friendly_missile( 
			std::string filename, 
			Point point, 
			SDL_Renderer* renderer, 
			Point target,
			int speed, 
			std::map<int, std::vector<Game_object*>> & game_objects, 
			Marker* marker,
			bool* power_up, 
			int sprite_width, 
			int sprite_height, 
			int sprite_speed 
			):Friendly_missile(filename, 
													point, 
													renderer, 
													target, 
													speed, 
													game_objects, 
													marker, 
													power_up, 
													sprite_width, 
													sprite_height, 
													sprite_speed)
{
}

void Super_friendly_missile::update() 
{
	if (get_state())
	{
		move(); 
		check_boundaries(); 
		if (reached_target(get_point(), get_target()))
		{
			marker -> destroy(); 
			explode(); 
		}
	}
	draw(get_angle()); 
}

void Super_friendly_missile::explode()
{
	set_state(false);
	set_speed(0);
	set_move(0,0);

	Point explosion_point{get_point().x - 44, get_point().y - 44};
	Point explosion_point1{get_point().x - 114, get_point().y - 114};
	Point explosion_point2{get_point().x - 114, get_point().y + 16};
	Point explosion_point3{get_point().x + 16, get_point().y - 114};
	Point explosion_point4{get_point().x + 16, get_point().y + 16};

	m[5].push_back(new Explosion{"sprites/explosion.png", explosion_point, get_renderer(), m, powerup, 96, 96, 10});
	m[5].push_back(new Explosion{"sprites/explosion.png", explosion_point1, get_renderer(), m, powerup, 96, 96, 10});
	m[5].push_back(new Explosion{"sprites/explosion.png", explosion_point2, get_renderer(), m, powerup, 96, 96, 10});
	m[5].push_back(new Explosion{"sprites/explosion.png", explosion_point3, get_renderer(), m, powerup, 96, 96, 10});
	m[5].push_back(new Explosion{"sprites/explosion.png", explosion_point4, get_renderer(), m, powerup, 96, 96, 10});

	destroy(); 
}

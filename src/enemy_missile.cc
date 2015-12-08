#include "enemy_missile.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <iostream>
#include "screen_dimensions.h"
#include "point.h"
#include "aabb.h"
#include <random>
#include <map>
#include <vector>
#include "house.h"

using namespace std;


Enemy_missile::Enemy_missile(
		std::string f,
		SDL_Renderer* r,
		int s,
		Point t,
		map<int, vector<Game_object*>> & m ):
	Missile(f, get_random_spawn(), r, t, s, m) 
{
//	set_random_target();
//	set_random_spawn();
	cout << m.size() << endl;
}

void Enemy_missile::update()
{
	//check collision, transform, destroy building etc.
	if (get_state())
	{
		move();
		check_boundaries();
		draw(angle);
	}
	//else
	//set speed 0
	//etc
}

void Enemy_missile::check_boundaries()
{
	Screen_dimensions sd;
	if (get_point().y > sd.SCREEN_H || 
			get_point().y < 0 || 
			get_point().x > sd.SCREEN_W || 
			get_point().x <0)
		{destroy();}
}

Point Enemy_missile::get_random_target()
{
	bool done{false};
	Point target;

	while (!done)
	{

		std::random_device rd;
		std::mt19937 gen(rd());

		std::uniform_int_distribution<int> dis(0, 5);

	cout << "hej" << endl;
  cout << m.size();
	cout << "efter tmp" << endl;
/*		if(dynamic_cast<House*>(m[1].at(dis(gen))) -> get_state())
		{
			cout << target.x << " "<< target.y << endl;
			target.x = m[1].at(dis(gen)) -> get_point().x; //16 half house width
			target.y = m[1].at(dis(gen)) -> get_point().y; //16 half house width
			done=true;
			cout << target.x << " "<< target.y << endl;
		}
	*/
	done = true;}
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
Point Enemy_missile::get_random_spawn()
{
	Screen_dimensions sd;
	std::random_device rd;
	std::mt19937 gen(rd());
	int x;
	int y;
	std::uniform_int_distribution<int> dis(1, sd.SCREEN_W);
	
	x = dis(gen);
	y = 1;

	Point p{x, y};
	return p;

}




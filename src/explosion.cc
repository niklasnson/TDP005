#include "collisionable.h"
#include "point.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.h"
#include <string>
#include <vector>
#include <map>
#include "explosion.h"
#include "collisionable.h"
#include "enemy_missile.h"

using namespace std;

Explosion::Explosion(std::string f, Point p, SDL_Renderer* r, map<int, vector<Game_object*>> & m):Collisionable(f, p, r), sprite{f, r, 96, 96, 10}, timer{0}, m(m) {}



void Explosion::update()
{
	sprite.draw(get_point());
	timer += 1;
	//cout << dynamic_cast<Enemy_missile*>(m[3].at(0)) << endl ;

	//cout << m[3].size() << endl;
	//cout << dynamic_cast<Enemy_missile*>(m[3].at(0)) << endl ;
	//cout << "before for" << endl;
	for (auto go : m[3])
	{
		//cout << "in for" << go <<endl;
		if (go -> get_point().x <= (get_point().x)+60 && (go -> get_point().x)+42 >= get_point().x 
         && go->get_point().y <= (get_point().y)+60 && (go->get_point().y)+69 >= get_point().y)
		{
			go -> destroy();
			cout << "BOOOOOOOOOOM HEADSHOT!!!" << endl;
		}
	}
		/*else
		{cout << "failed check" << endl;}
	}*/
	if (timer > 40)
	{
		destroy();
	}
}

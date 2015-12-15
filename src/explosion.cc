#include "point.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>
#include <map>
#include "explosion.h"
#include "enemy_missile.h"
#include "powerup.h"

using namespace std;

Explosion::Explosion(
		std::string f,
		Point p,
		SDL_Renderer* r,
		map<int, vector<Game_object*>> & m,
		bool* po,
		int sW, 
		int sH, 
		int sS
		)
	:Game_object(f, p, r, sW, sH, sS), timer{0}, m(m), powerup{po} {}



void Explosion::update()
{
	sprite.draw(get_point());
	timer += 1;
	
	for (auto go : m[3])
	{
		if (go -> get_point().x <= (get_point().x)+60 && (go -> get_point().x)+42 >= get_point().x 
         && go->get_point().y <= (get_point().y)+60 && (go->get_point().y)+69 >= get_point().y)
		{
			go -> destroy();
			cout << "BOOOOOOOOOOM HEADSHOT!!!" << endl;
			//cout << "before" << endl;
			if(dynamic_cast<Powerup*>(go) != nullptr)
			{
				cout<<"POWERUPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP!!!!!!!!" << endl;
				*powerup = true;
				cout << "after true" << endl;
				cout << powerup << endl;
			}
		}
	}

	if (timer > 40)
	{
		destroy();
	}
}

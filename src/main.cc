#include <vector>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "static.h"
#include "screen_dimensions.h"
#include "rotatable.h"
#include "point.h"
#include "player.h"
#include "missile.h"
#include "house.h"
#include "game_object.h"
#include "friendly_missile.h"
#include "enemy_missile.h"
#include "collisionable.h"
#include "aabb.h"
#include "marker.h"
#include <map>

using namespace std;

int main()
{
	Screen_dimensions sd;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	window = SDL_CreateWindow( "KOMRAD KOMMAND", SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, sd.SCREEN_W, 
					sd.SCREEN_H, SDL_WINDOW_SHOWN );
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	SDL_SetRenderDrawColor(renderer, 255, 255, 226, 0);

	Point point_house_0{21, sd.SCREEN_H - 136};
	Point point_house_1{140, sd.SCREEN_H - 136};
	Point point_house_2{240, sd.SCREEN_H - 136};
	Point point_house_3{1010,sd. SCREEN_H - 136};
	Point point_house_4{890, sd.SCREEN_H - 136};
	Point point_house_5{770, sd.SCREEN_H - 136};

	Point missile{50, 50};
	Point missilet{500, 500};
	Point speed{5, 5};

/*	vector<Game_object*> v;
	vector<Game_object*> vv;
	vector<Game_object*> vvv;
	vector<Game_object*> vvvv;
	vector<Game_object*> vvvvv;
*/


	map<int, vector<Game_object*>> m;
/*	m.emplace(1, v);
	m.emplace(2, vv);
	m.emplace(3, vvv);
	m.emplace(4, vvvv);
	m.emplace(5, vvvvv);
*/
	Point point_player_rotatable{555, sd.SCREEN_H -100};

	m[5].push_back(new Player{"sprites/clauncher.png", point_player_rotatable, renderer, Point{520, sd.SCREEN_H -110}});
	m[1].push_back(new House{"sprites/house.png", point_house_0, renderer});
	m[1].push_back(new House{"sprites/house.png", point_house_1, renderer});
	m[1].push_back(new House{"sprites/house.png", point_house_2, renderer});
	m[1].push_back(new House{"sprites/house.png", point_house_3, renderer});
	m[1].push_back(new House{"sprites/house.png", point_house_4, renderer});
	m[1].push_back(new House{"sprites/house.png", point_house_5, renderer});
	m[5].push_back(new Static{"sprites/bunker.png", Point{520, sd.SCREEN_H - 136}, renderer});
	m[5].push_back(new Static{"sprites/border.png", Point{0, sd.SCREEN_H - 40}, renderer});
	m[5].push_back(new Static{"sprites/russian_star.png", Point{532, sd.SCREEN_H - 40}, renderer});

	bool quit{false};
	SDL_Event e;

	while(!quit)
	{
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			if(e.type == SDL_MOUSEBUTTONUP)
			{
				Point mouse_location{e.button.x, e.button.y};
				Marker* mark = new Marker("sprites/marker.png", mouse_location, renderer);
				m[2].push_back(mark);
				m[4].push_back(new Friendly_missile{"sprites/cplayer.png", point_player_rotatable, renderer, mouse_location, 4, m, mark});
				m[3].push_back(new Enemy_missile{"sprites/cda_bomba_0.png", 
						get_random_spawn(), renderer, get_random_target(), 3});
			}
		}
		SDL_RenderClear(renderer); 
		for(pair<const int, vector<Game_object*>>& a : m)
		{
		//cout << "Gar ingeom grejer" << endl;	
			for(vector<Game_object*>::iterator it{a.second.begin()}; it != a.second.end();)
			{
				if (!(*it) -> is_destroyed())
				{
					(*it) -> update();
					++it;
				}
				else
				{
					//cout << "BEFORE NULL: " << *it << endl;
					//o -> release_texture();
					Game_object* todel = *it;
					//cout << a.second.size() << endl;

					it = a.second.erase(it);
					//cout << a.second.size() << endl;
					//cout << todel << endl;
					//cout << a.second.size();
					delete todel;
					//*it = nullptr;
					//cout << "AFTER DEL" << endl;
				}
			}
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	return 0;
}

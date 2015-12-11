#include <iostream>
#include "endgame.h"
#include "game.h"
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
#include "game_state.h"
#include "game.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <random>
#include <chrono>
#include "powerup.h"



using namespace std;

Endgame::Endgame(SDL_Renderer* r, int l, int & score):Game_state(r, l), score{score}
{
	init();
}

vector<pair<int, string>> Endgame::load_highscore()
{
	ifstream ifs{"highscore.txt"}; 	
	string line;
	vector<pair<int, string>> highscore;

	if(!ifs)
	{
		cout << " ERROR : COULD NOT LOAD HIGHSCORE. " << endl;
	}

	while (getline(ifs, line)) 
	{
		int playerscore;
		string name;
		istringstream iss{line};

		iss >> playerscore;
		iss >> name;
		pair<int, string> entry{playerscore, name};

		highscore.emplace(highscore.end(), entry);
		
	}
	return highscore;
}

void Endgame::init()
{
	
	vector<pair<int, string>> highscore;
	highscore = load_highscore();

	cout << "your score: " << score << endl;
	cout << "lowest highscore: " << highscore.back().first << endl;

	if( score > ((highscore.back()).first))
	{
		cout << "ENTER HIGHSCORE" << endl;		
	}

	Point pos{100, 0};

	int place{0};

	for (auto l : highscore)
	{
		pos.y += 100;
	  place += 1;
		ostringstream scoreline;
		scoreline << place << ":.........." << l.second << "..........." << l.first;
		t.emplace(t.end(), new Text{scoreline.str(), pos, renderer});
	}

	SDL_Texture* cursor;
	SDL_Surface* loaded_surface = IMG_Load("sprites/aim.png");
	cursor = SDL_CreateTextureFromSurface(renderer, loaded_surface);
	SDL_FreeSurface(loaded_surface);

	SDL_Rect cursor_hitbox;
	SDL_QueryTexture(cursor, NULL, NULL, &cursor_hitbox.w, &cursor_hitbox.h);
	if (cursor == nullptr)
		cout << "FAILEDTOLOAD cursor" << endl;SDL_ShowCursor(0);
	
	SDL_Event e;
	bool end{false};

	m[1].push_back(new House{"sprites/menu score.png", Point{0, 0}, renderer, 96, 96, 0});

	while(!end)
	{
		//cout << score << endl;

		SDL_RenderClear(renderer);

		while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT )
			{
				end = true;
			}
			if(e.type == SDL_MOUSEBUTTONUP)
			{
				end = true;
			}
		}

		for(auto p : m)
		{
			for(auto go:p.second)
			{
				go -> update();
			}
		}

		//Deletes all text 
		//for(vector<Text*>::iterator it{t.begin()}; it != t.end();)
		//{
		//	Text* todel = *it; 
		//	it = t.erase(it);
		//	delete todel; 
		//}

		//prints text on screen
		for(vector<Text*>::iterator it{t.begin()}; it != t.end(); ++it) 
		{
			(*it) -> update();
		}




	SDL_GetMouseState(&cursor_hitbox.x, &cursor_hitbox.y);
	cursor_hitbox.x += 2;
	cursor_hitbox.y += 2;
	SDL_RenderCopy(renderer, cursor, NULL, &cursor_hitbox);

	SDL_RenderPresent(renderer);
	SDL_Delay(10);
	}


}

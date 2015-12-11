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
#include <iomanip>


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

string Endgame::player_input()
{
	bool done{false};
		SDL_Event e;
		SDL_StartTextInput();
		string input{"DEFAULT TEXT"};
	//	t.emplace(t.end(), new Text{"CONGRATZ HIGHSCORE ENTER NAME", Point{0, 0});
	//	t.emplace(t.end(), new Text{input, Point{0, 50});
	while (!done)
	{
		SDL_RenderClear(renderer);
		while( SDL_PollEvent( &e ) != 0)
		{
			if( e.type == SDL_QUIT ) // || e.type == SDLK_RETURN)
			{
				done = true;
			}
			else if( e.type == SDL_KEYDOWN )
     	{
     	//Handle backspace
     		if( e.key.keysym.sym == SDLK_BACKSPACE && input.length() > 0 )
      	{
     			//lop off character
    				input.pop_back();
    		}
				if( e.key.keysym.sym == SDLK_RETURN)
				{
					done = true;
				}
			}
			else if( e.type == SDL_TEXTINPUT )
			{
				input += e.text.text;
			}
		}
		//Deletes all text 
		for(vector<Text*>::iterator it{t.begin()}; it != t.end();)
		{
			Text* todel = *it; 
				it = t.erase(it);
			delete todel; 
		}
		t.emplace(t.end(), new Text{"CONGRATZ HIGHSCORE ENTER NAME", Point{0, 0}, renderer});
		t.emplace(t.end(), new Text{input, Point{0, 50}, renderer});
		//prints text on screen
		for(vector<Text*>::iterator it{t.begin()}; it != t.end(); ++it) 
		{
				(*it) -> update();
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	SDL_StopTextInput();
	return input;
}

void Endgame::show_highscore(vector<pair<int, string>> highscore)
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	Point pos{425, 350};
	int place{0};
  SDL_ShowCursor(1);	
	SDL_Event e;

	bool end{false};

	for (auto l : highscore)
	{
		pos.y += 30;
	  place += 1;
		ostringstream scoreline;
		scoreline << place
							<< std::setw(6) << std::setfill(' ') << l.second  << "  "
							<< std::setw(13) << std::setfill('0') << l.first << "  ";
		t.emplace(t.end(), new Text{scoreline.str(), pos, renderer});
	}

	m[1].push_back(new House{"sprites/medal.png", Point{450, 90}, renderer, 256, 256, 0});

	while(!end)
	{
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
		for(vector<Text*>::iterator it{t.begin()}; it != t.end(); ++it) 
		{
			(*it) -> update();
		}
	SDL_RenderPresent(renderer);
	SDL_Delay(10);
	}

}



void Endgame::init()
{
	vector<pair<int, string>> highscore;
	highscore = load_highscore();

	cout << "your score: " << score << endl;
	cout << "lowest highscore: " << highscore.back().first << endl;
	
	if( score > ((highscore.back()).first))
	{
		string input;
		input = player_input();
	}
	show_highscore(highscore); 
}

#include "endgame.h"

Endgame::Endgame(SDL_Renderer* r, int l, int & score, bool & quit):Game_state(r, l, quit), score{score}
{
	init();
}

std::vector<std::pair<int, std::string>> Endgame::load_highscore()
{
	std::ifstream ifs{"highscore.txt"}; 	
	std::string line;
	std::vector<std::pair<int, std::string>> highscore;

	if(!ifs)
	{
		std::cout << " ERROR : COULD NOT LOAD HIGHSCORE. " << std::endl;
	}

	while (getline(ifs, line)) 
	{
		int playerscore;
		std::string name;
		std::istringstream iss{line};

		iss >> playerscore;
		iss >> name;
		std::pair<int, std::string> entry{playerscore, name};

		highscore.emplace(highscore.end(), entry);
		
	}
	return highscore;
}

std::string Endgame::player_input()
{
	bool done{false};
	bool render{true};
	SDL_Event e;
	SDL_StartTextInput();
	std::string input{"AAA"};
	while (!done && !quit)
	{
		while( SDL_PollEvent( &e ) != 0)
		{
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			else if( e.type == SDL_KEYDOWN )
     	{
     	//Handle backspace
     		if( e.key.keysym.sym == SDLK_BACKSPACE && input.length() > 0 )
      	{
     			//lop off character
    				input.pop_back();
						render = true;
    		}
				if( e.key.keysym.sym == SDLK_RETURN)
				{
					done = true;
				}
			}
			else if( e.type == SDL_TEXTINPUT )
			{
				input += e.text.text;
				render = true;
			}
		}
		if (render)
		{
			SDL_RenderClear(renderer);
		}
		//Deletes all text
		if (render)
		{
			for(std::vector<Text*>::iterator it{t.begin()}; it != t.end();)
			{
				Text* todel = *it; 
				it = t.erase(it);
				delete todel; 
			}

			t.emplace(t.end(), new Text{"CONGRATZ HIGHSCORE ENTER NAME", Point{400, 350}, renderer});
			t.emplace(t.end(), new Text{input, Point{550, 570}, renderer});

			//prints text on screen
			for(std::vector<Text*>::iterator it{t.begin()}; it != t.end(); ++it) 
			{
					(*it) -> update();
			};
			render = true;
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
		render = false;
	}
	SDL_StopTextInput();
	for(std::vector<Text*>::iterator it{t.begin()}; it != t.end();)
	{
		Text* todel = *it; 
		it = t.erase(it);
		delete todel; 
	}

	return input;
}

void Endgame::show_highscore(std::vector<std::pair<int, std::string>> & highscore)
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
		std::ostringstream scoreline;
		scoreline << place
							<< std::setw(6) << std::setfill(' ') << l.second  << "  "
							<< std::setw(13) << std::setfill('0') << l.first << "  ";
		t.emplace(t.end(), new Text{scoreline.str(), pos, renderer});
	}

	m[1].push_back(new House{"sprites/medal.png", Point{450, 90}, renderer, 256, 256, 0});

	while(!end && !quit)
	{
		SDL_RenderClear(renderer);
		while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			if(e.type == SDL_KEYDOWN)
			{
				end = true;
			};
		}
		for(auto p : m)
		{
			for(auto go:p.second)
			{
				go -> update();
			}
		}
		for(std::vector<Text*>::iterator it{t.begin()}; it != t.end(); ++it) 
		{
			(*it) -> update();
		}


	SDL_RenderPresent(renderer);
	SDL_Delay(10);
	}
	for(std::vector<Text*>::iterator it{t.begin()}; it != t.end();)
	{
		Text* todel = *it; 
		it = t.erase(it);
		delete todel; 
	}

	for(std::pair<const int, std::vector<Game_object*>>& a : m)
	{
		for(std::vector<Game_object*>::iterator it{a.second.begin()}; it != a.second.end();)
		{	
 			Game_object* todel = *it;
 			it = a.second.erase(it);
		  delete todel;
		}
  }
}

void Endgame::update_file(std::vector<std::pair<int, std::string>> highscore)
{
	std::ofstream file;
	file.open("highscore.txt");
	for(auto l : highscore)
	{
		file << l.first << "      " << l.second << '\n';
	}
	file.close();
}

void Endgame::init()
{

	
		std::vector<std::pair<int, std::string>> highscore;
		highscore = load_highscore();
	
		if( score > ((highscore.back()).first))
		{
			std::string input;
			input = player_input();
	
			input.erase(3); //slices input at 3 letters
			std::pair<int, std::string> newline{score, input};
			highscore.emplace(highscore.begin(), newline);
		
		
			stable_sort(highscore.begin(), highscore.end(),[]
				(std::pair<int, std::string> a, std::pair<int, std::string> b) -> bool
				{
					return a.first > b.first;
				});
		
			highscore.erase(highscore.end()-1);
			update_file(highscore);
		}
		show_highscore(highscore); 
	
}

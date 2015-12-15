#include "start.h"

Start::Start(SDL_Renderer* r, int l):Game_state(r, l)
{
	init();
}

void Start::init()
{
	SDL_Texture* cursor;
	SDL_Surface* loaded_surface = IMG_Load("sprites/aim.png");
	cursor = SDL_CreateTextureFromSurface(renderer, loaded_surface);
	SDL_FreeSurface(loaded_surface);

	SDL_Rect cursor_hitbox;
	SDL_QueryTexture(cursor, NULL, NULL, &cursor_hitbox.w, &cursor_hitbox.h);
	
	if (cursor == nullptr)
	{
		std::cout << "FAILED TO LOAD cursor" << std::endl;
		SDL_ShowCursor(0);
	}
	
	SDL_Event e;
	bool end{false};

	m[1].push_back(new House{"sprites/scaledmenu.png", Point{0, 0}, renderer, 1140, 800, 1});

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
		for(std::pair<const int, std::vector<Game_object*>>& a : m)
		{
			for(std::vector<Game_object*>::iterator it{a.second.begin()}; it != a.second.end();)
			{
				if (!(*it) -> is_destroyed())
				{
					(*it) -> update();
					++it;
				}
			}
		}
		SDL_GetMouseState(&cursor_hitbox.x, &cursor_hitbox.y);
		cursor_hitbox.x += 2;
		cursor_hitbox.y += 2;
		SDL_RenderCopy(renderer, cursor, NULL, &cursor_hitbox);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
}

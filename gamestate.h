#ifndef GAME_STATE_h
#define GAME_STATE_h

class Gamestate
{
	public:
		Gamestate();
		void set_renderer(SDL_RENDERER*);
		SDL_RENDERER* get_renderer() const;
		
	private:
		SDL_RENDERER* renderer;
		SDL_WINDOW* window;

};

#endif

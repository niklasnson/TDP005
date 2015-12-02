#ifndef MISSILE_h
#define MISSILE_h

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "rotatable.h"
#include "point.h"
#include "aabb.h"

class Missile : public Rotatable
{
	public:
		Missile(std::string, Point, SDL_Renderer*, Point, int);
		void update();
		int get_speed();
		void set_speed(int const&);
		bool get_state();
		void set_state(bool); 

	private:
			int speed;
			bool is_missile;
			double curr_x;
			double curr_y;
			double move_x;
			double move_y;
};

#endif

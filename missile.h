#ifndef MISSILE_h
#define Missile_h

#include "rotatable.h"

class Missile : public Rotatable
{
	public:
		Missile();
		void update() const;
		Point get_speed() const;
		void set_speed(Point const&);
		bool get state() const;
		void set_state(bool const&); 

	private:
			Point speed;
			bool is_missile;
};

#endf

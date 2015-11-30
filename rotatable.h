#ifndef ROTATABLE_h
#define ROTATABLE_h

#include "collisionable.h"

class Rotatable : public collisionable
{
	public:
	Rotatable()
	void update() const;
	void calculate_allignment() const;
	Point get_target() const;
	void set_target(Point const& target);

	private:
	Point target;

	
};

#endif

#ifndef ROTATABLE_h
#define ROTATABLE_h

class Rotatable : public Collisionable
{
	public:
	Rotatable(std::string, Point, SDL_Renderer*, Point)
	void update() const;
	void calculate_allignment() const;
	Point get_target() const;
	void set_target(Point const& target);
	double get_angle(); 
	void set_angle(); 

	private:
	Point target;
  double angle;
	
};

#endif

#ifndef MISSILE_h
#define MISSILE_h

class Missile : public Rotatable
{
	public:
		Missile(std::string, Point, SDL_Renderer*, Point, Point);
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

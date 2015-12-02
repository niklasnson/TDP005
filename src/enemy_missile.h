#ifndef ENEMYMISSILE_h
#define ENEMYMISSILE_h

class Enemy_missile : public Missile
{
	public:
		Enemy(std::string, Point, SDL_Renderer*, Point);
		void update();

	private:
		

};

#endif

#ifndef PLAYER_h
#define PLAYER_h

class Friendly_missile : public Missile
{
	public:
		Player(std::string, Point, SDL_Renderer*, Point);
		void update() const;
};


#endif

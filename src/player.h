#ifndef PLAYER_h 
#define PLAYER_h

class Player : public Rotatable 
{
	Player(std::string, Point, SDL_Renderer*, Point, Point);
};

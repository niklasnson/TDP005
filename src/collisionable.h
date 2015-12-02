#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H
class Collisionable : public GameObject
{
public:
	Collisionable(std::string, Point, SDL_Renderer*); 
	virtual void update() = 0; 
	bool collision(); 
protected:
	AABB boundingbox;
};
#endif

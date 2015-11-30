#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H
class Collisionable : public GameObject
{
public:
	Collisionable(); 
	void Update(); 
	bool Collision(); 
private: 
};
#endif

#ifndef BLOCK_h
#define BLOCK_h 



class Block 
{
public: 
	Block();
	void add_house(Game_object*);
	int number_of_houses(); 
	bool city_destroyed();
	Point get_random_target();

private: 

}; 
#endif 

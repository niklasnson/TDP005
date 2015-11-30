#ifndef HOUSE_h
#define HOUSE_h 

class House : public Block 
{
public: 
	House();  
	void update(); 
	bool get_state(): 
	void set_state(); 

private: 
	bool is_destroyed;
};

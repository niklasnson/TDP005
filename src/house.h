#ifndef HOUSE_h
#define HOUSE_h 

class House : public Colisionable 
{
public: 
	House();  
	void update(); 
	bool get_state(): 
	void set_state(); 

private: 
	bool intact;
};

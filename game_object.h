#ifndef GameObject_h 
#define GameObject_h

Class GameObject 
{
public: 
	virtual void update();
	void draw(); 

private: 
	string image;
	Point cords; 
};
#endif



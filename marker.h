#ifndef MARKER_h 
#define MARKER_h


class Marker : public Static 
{
public:
	Marker(std::string, Point, SDL_Renderer*);
	void Update(); 
private: 

};
#endif


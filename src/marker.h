#ifndef MARKER_h 
#define MARKER_h


class Marker : public Static 
{
public:
	Marker(std::string, Point, SDL_Renderer*, int);
	void update(); 
	void set_frame(int);
	int get_frame();
private: 
	int frame;
};
#endif


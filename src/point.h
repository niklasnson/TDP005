#ifndef POINT_h
#define POINT_h


struct Point
{
	int x;
	int y;

	Point(Point const& a): x{a.x}, y{a.y}{}
	Point(int a, int b): x{a}, y{b}{}
	//Point& operator=(Point const& rhs):x{rhs.x}, y{rhs.y}{}
};
#endif

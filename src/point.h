#ifndef POINT_h
#define POINT_h

/**
 * Point struct.
 * Points are used to show sprites and text.
 */
struct Point
{
	int x; /**< a int value. */
	int y; /**< a int value. */
	
	//! Default constructor.
  Point():Point(0, 0){}
  /*!
	 * Constructor for Point.
   * @param point - a Point object.
   */
	Point(Point const& a): x{a.x}, y{a.y}{}
	/*! 
   * Constructor for Point.
   * @param a - a int argument.
   * @param b - a int argument. 
   */
  Point(int a, int b): x{a}, y{b}{}
	//Point& operator=(Point const& rhs):x{rhs.x}, y{rhs.y}{}
};
#endif

#include "aabb.h"
#include <iostream>

using namespace std;

AABB::AABB(int top, int left, int bottom, int right)
  :top{top}, left{left}, bottom{bottom}, right{right}
{
  if (top > bottom) 
  {
    swap(top, bottom); 
  }

  if (left > right) 
  {
    swap(left, right);
  }
}

AABB::AABB(Point const& top_left, Point const& bottom_right)
  :AABB(top_left.y, top_left.x, bottom_right.y, bottom_right.x){}

bool AABB::contain(int x, int y) const 
{
  if (x >= left && x <= right && y >= top && y <= bottom)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool AABB::contain(Point const& a) const
{
  return AABB::contain(a.x, a.y);
}

bool AABB::intersect(AABB const& a) const  
{
  return left <= a.right && right >= a.left 
         && top <= a.bottom && bottom >= a.top;
}

AABB AABB::min_bounding_box(AABB const& a) const 
{
  int top_most_coordinate{top};
  int left_most_coordinate{left};
  int bottom_most_coordinate{bottom};
  int right_most_coordinate{right};

  if (a.top < top)
  {
    top_most_coordinate = a.top;
  }

  if (a.left < left)
  {
    left_most_coordinate = a.left;
  }

  if (a.bottom > bottom)
  {
    bottom_most_coordinate = a.bottom;
  }

  if (a.right > right)
  {
    right_most_coordinate = a.right;
  }

  AABB box(top_most_coordinate, left_most_coordinate, 
           bottom_most_coordinate, right_most_coordinate);
  return box;
}


bool AABB::will_not_collide(AABB const& from, Point const& to) const
{
  int to_box_height{from.bottom - from.top};
  int to_box_width{from.right - from.left};
  AABB to_box{to.y, to.x, to.y+to_box_height, to.x+to_box_width};
  AABB bounding_box{to_box.min_bounding_box(from)};
  return !intersect(bounding_box);
}


bool AABB::collision_point(AABB const& from, Point const& to, Point& where) const
{
  int from_box_height{from.bottom - from.top};
  int from_box_width{from.right - from.left};
  int distance_y{to.y - from.top};
  int distance_x{to.x - from.left};
  int abs_distance_y{abs(from.top - to.y)};
  int abs_distance_x{abs(from.left - to.x)};
  double speed_y{static_cast<double>(
                 distance_y)/max(abs_distance_x, abs_distance_y)};
  double speed_x{static_cast<double>(
                 distance_x)/max(abs_distance_y, abs_distance_x)};
  int number_of_steps{abs(static_cast<int>(
                 abs_distance_x / speed_x + 0.5))};

  int last_location_x{from.left};
  int last_location_y{from.top};
  for (int i{0}; i <= number_of_steps; i++)  
  {
    int temp_y_cord{from.top + static_cast<int>(speed_y * i + 0.5)};
    int temp_x_cord{from.left + static_cast<int>(speed_x * i + 0.5)};
    
    AABB temp_box{temp_y_cord, temp_x_cord, 
                  temp_y_cord + from_box_height, 
                  temp_x_cord + from_box_width};
    if (intersect(temp_box))
      {
      where = Point {last_location_x, last_location_y};
      return true;
      }
    last_location_x = temp_x_cord;
    last_location_y = temp_y_cord;
  }
  return false;
}


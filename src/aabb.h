#ifndef AABB_H
#define AABB_H
#include "point.h"

class AABB
{
public:
  AABB(int top, int left, int bottom, int right);
  AABB(Point const& top_left, Point const& bottom_right);
  bool contain(int x, int y) const;
  bool contain(Point const& a) const;
  bool intersect(AABB const& a) const;
  AABB min_bounding_box(AABB const& a) const;
  bool will_not_collide(AABB const&, Point const&) const;
  bool collision_point(AABB const& from, Point const& to, Point& where) const;
private:
  int top{0};
  int left{0};
  int bottom{0};
  int right{0};
  Point where{0,0}; 
};

#endif


#include "problem4.h"
#include <math.h>
Triangle getLarger(Triangle first, Triangle second)
{
  double area1 = Area(first.a, first.b, first.c);
  double area2 = Area(second.a, second.b, second.c);

  if(area1 >= area2){
    return first;
  }
  else
    return second;
}

double Area( Point a,  Point b, Point c)
{
  double area = fabs(0.5*(a.x*b.y + b.x*c.y + c.x*a.y - a.x*c.y - b.x*a.y - c.x*b.y));
  return area;
}

  





  // Fill in this function

  // You'll want to replace this with something that returns a meaningful
  // result.
  //return(t); 



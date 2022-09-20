#include "../includes/Point.hpp"

int  getPos(Point const a, Point const b, Point const c){
     Fixed res = (b.getX() - a.getX()) * (c.getY() - a.getY())
          - (b.getY() - a.getY()) * (c.getX() - a.getX());
     
     if (res == 0)
          return (0);
     else if (res > 0)
          return (1);
     else
          return (-1);
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
     int res = getPos(a, b, p) + getPos(b, c, p) + getPos(c, a, p);

     return (res == 3 || res == -3 ? true : false);
}
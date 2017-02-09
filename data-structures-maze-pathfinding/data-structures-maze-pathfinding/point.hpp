//
//  point.hpp
//  data-structures-maze-pathfinding
//
//  Created by Alexander Cochrane on 2017-02-09.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#ifndef point_hpp
#define point_hpp

#include <stdio.h>

class Point {
    Point* parent = NULL;
    bool closed = false;
    bool opened = false;
    
    bool traversable;
    
    int x;
    int y;
    int fCost;
    int gCost;
    int hCost;
    
    Point(int x, int y, bool traversable) : x(x), y(y), traversable(traversable){}
    
    void calculate(Point* end);
    void calculate(Point* newParent, Point* end);
};

#endif /* point_hpp */

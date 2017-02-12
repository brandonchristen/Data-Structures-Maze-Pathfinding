//
//  point.cpp
//  data-structures-maze-pathfinding
//
//  Created by Alexander Cochrane on 2017-02-09.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include "point.hpp"

void Point::calculate(Point* end) {
    if (parent!=NULL) {
        gCost = parent->gCost;
    }
    else {
        gCost = 0;
    }
    gCost += ((parent->x>this->x)? parent->x - this->x : this->x - parent->x)
            +((parent->y>this->y)? parent->y - this->y : this->y - parent->y);
    hCost = ((end->x>this->x)? end->x - this->x : this->x - end->x)
           +((end->y>this->y)? end->y - this->y : this->y - end->y);
    fCost = gCost + hCost;
}

void Point::calculate(Point* newParent, Point* end) {
    this->parent = newParent;
    calculate(end);
}

bool Point::newParentIsBetter(Point* testParent) {
    return testParent->gCost < parent->gCost;
}

//
//  list.hpp
//  data-structures-maze-pathfinding
//

#ifndef list_hpp
#define list_hpp

#include <algorithm>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include "Point.hpp"

class List {
private:
    Point** items;
    int length = 0;
public:
    void push_back(Point* point);
    Point* get(int location);
    bool remove(Point* point);
    int size();
    bool isEmpty();
};
#endif /* list_hpp */

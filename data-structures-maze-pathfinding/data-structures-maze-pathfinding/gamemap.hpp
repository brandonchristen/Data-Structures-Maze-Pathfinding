//
//  gamemap.hpp
//  data-structures-maze-pathfinding
//

#ifndef gamemap_hpp
#define gamemap_hpp

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <type_traits>
#include "point.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "list.hpp"

class GameMap {
public:
    std::string filename;
    Point*** map;
    Point* start;
    Point* end;
    Stack path;
    int NUM_CYCLES_TIMEOUT;
    void aStarPathFind();
    GameMap(Point*** map);
};

#endif /* gamemap_hpp */

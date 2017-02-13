//
//  gamemap.hpp
//  data-structures-maze-pathfinding
//
//  Created by Alexander Cochrane on 2017-02-09.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
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
    void aStarPathFind();
    GameMap(Point*** map);
};

#endif /* gamemap_hpp */

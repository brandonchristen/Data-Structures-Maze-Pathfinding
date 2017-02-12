//
//  gamemap.cpp
//  data-structures-maze-pathfinding
//
//  Created by Alexander Cochrane on 2017-02-09.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include "gamemap.hpp"

GameMap::GameMap(Point*** map) :
    map(map),
    start(map[1][0]),
    end(map[(sizeof map / sizeof map[0])-1][sizeof map[0] / sizeof(Point)]) {}

void GameMap::aStarPathFind() {
    Point* current;
    List openPoints;
    List closedPoints;
    bool b = true;
    
    openPoints.push_back(start);
    start->opened = true;
}

//
//  gamemap.hpp
//  data-structures-maze-pathfinding
//
//  Created by Alexander Cochrane on 2017-02-09.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#ifndef gamemap_hpp
#define gamemap_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
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

std::ostream& operator<< (std::ostream& os, GameMap gameMap) {
    int rows = sizeof gameMap.map / sizeof gameMap.map[0];
    int cols = sizeof gameMap.map[0] / sizeof(Point);
    char a[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            a[i][j] = gameMap.map[i][j]->data;
        }
    }
    
    Point* point = gameMap.end;
    while (true) {
        a[point->x][point->y] = '#';
        if (point->parent == NULL) break;
        point = point->parent;
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            os << (char)a[i][j];
        }
        os << std::endl;
    }
    
    return os;
}

#endif /* gamemap_hpp */

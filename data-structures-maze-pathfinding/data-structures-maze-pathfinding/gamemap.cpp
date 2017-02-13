//
//  gamemap.cpp
//  data-structures-maze-pathfinding
//
//  Created by Alexander Cochrane on 2017-02-09.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include "gamemap.hpp"

GameMap::GameMap(Point*** map) :
    map(map), start(map[1][0]) {}

void GameMap::aStarPathFind() {
    Point* current;
    Point* child;
    List openPoints;
    
    if (end==NULL) throw std::invalid_argument("Point End not defined");
    
    start->calculate(end);
    openPoints.push_back(start);
    start->opened = true;
    current = start;
    
    while (true/* TODO: add timeout */) {
        // look for the Point with the lowest fCost
        for (int i = 0; i < openPoints.size(); i++) {
            if (openPoints.isEmpty()) continue;
            if (openPoints.get(i)->fCost <= current->fCost) {
                current = openPoints.get(i);
            }
        }
        
        if (current==end) break;
        
        openPoints.remove(current);
        current->opened = false;
        current->closed = true;
        
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                // if i and j are the current point's x and y, or the movement is diagonal, skip this.
                if ( (i==0&&j==0) || (i!=0&&j!=0) ) continue;
                if (current->x+i < start->x ||
                    current->y+j < start->y ||
                    current->x+i > end->x ||
                    current->y+j > end->y) continue;
                
                child = map[current->x+i][current->y+j];
                // if that point has already been checked or is a wall, skip this.
                if (child->closed||!child->traversable) continue;
                
                if (child->opened) {
                    if (child->newParentIsBetter(current)) {
                        child->calculate(current, end);
                        std::cout << "Calculating point at " << child->x << ", " << child->y << ":" << std::endl;
                        std::cout << "\tfCost: " << child->fCost << std::endl;
                        std::cout << "\tgCost: " << child->gCost << std::endl;
                        std::cout << "\thCost: " << child->hCost << std::endl << std::endl;
                    }
                }
                else {
                    child->opened = true;
                    child->calculate(current, end);
                    openPoints.push_back(child);
                    std::cout << "Opened & Calculating point at " << child->x << ", " << child->y << ":" << std::endl;
                    std::cout << "\tfCost: " << child->fCost << std::endl;
                    std::cout << "\tgCost: " << child->gCost << std::endl;
                    std::cout << "\thCost: " << child->hCost << std::endl << std::endl;
                }
            }
        }
    }
    
    current = end;
    while (current!=NULL) {
        path.push_back(current);
        current = current->parent;
    }
}

















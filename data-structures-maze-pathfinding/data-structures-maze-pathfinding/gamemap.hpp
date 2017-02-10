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

class GameMap {
    std::string filename;
public:
    Point** map;
    
};

#endif /* gamemap_hpp */

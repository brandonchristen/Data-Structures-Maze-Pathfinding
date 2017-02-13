//
//  fileloader.hpp
//  data-structures-maze-pathfinding
//
//  Created by Alexander Cochrane on 2017-02-09.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#ifndef fileloader_hpp
#define fileloader_hpp

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

#include "point.hpp"
#include "stack.hpp"

class FileLoader {
    int numRows;
    int rowLength;
    std::istream& safeGetLine(std::istream& is, std::string& t);
public:
    Point* end;
    Point*** loadFile(const char* filename);
    void saveFile(Point*** map, Stack path, const char* filename);
};

#endif /* fileloader_hpp */

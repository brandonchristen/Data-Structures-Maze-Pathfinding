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

class FileLoader {
    int numRows;
    int rowLength;
    char** loadFile(std::string filename);
    void saveFile(char** map, std::string filename);
};

#endif /* fileloader_hpp */

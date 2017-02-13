//
//  main.cpp
//  data-structures-maze-pathfinding
//
//  Created by Alexander Cochrane on 2017-02-08.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include <iostream>
#include "fileloader.hpp"
#include "gamemap.hpp"

int main(int argc, const char * argv[]) {
	FileLoader fl;
    if (argc<1) {
        std::cout << "Please enter a filename." << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::cout << argv[1] << std::endl;
    try {
        GameMap gm(fl.loadFile(filename.c_str()));
        gm.end = fl.end;
        gm.aStarPathFind();
        fl.saveFile(gm.map, gm.path, filename.c_str());
    }
    catch (std::invalid_argument e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

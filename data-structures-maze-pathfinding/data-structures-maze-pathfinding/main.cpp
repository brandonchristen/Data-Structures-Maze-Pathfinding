//
//  main.cpp
//  data-structures-maze-pathfinding
//

#include <iostream>
#include "fileloader.hpp"
#include "gamemap.hpp"

int main(int argc, const char * argv[]) {
	FileLoader fl;
    if (argc<2) {
        std::cout << "Please enter a filename." << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::cout << argv[1] << std::endl;
    try {
        GameMap gm(fl.loadFile(filename.c_str()));
        gm.end = fl.end;
        if (argc>2) {
            gm.NUM_CYCLES_TIMEOUT = atoi(argv[2]);
        }
        else gm.NUM_CYCLES_TIMEOUT = gm.end->y*100;
        gm.aStarPathFind();
        fl.saveFile(gm.map, gm.path, filename.c_str(), gm.end);
    }
    // catch invalid filename
    catch (std::invalid_argument e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    // catch no map path or cycle timeout
    catch (std::length_error e) {
        std::cout << e.what() << std::endl;
        return 2;
    }
    
    return 0;
}

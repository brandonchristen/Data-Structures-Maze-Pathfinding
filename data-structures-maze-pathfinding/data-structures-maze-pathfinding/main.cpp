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

	GameMap gm;
	FileLoader fl;
    // insert code here...
    if (argc<1) {
        std::cout << "Please enter a filename." << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    int curPosx = 0;
	int curPosy = 0;
	gm.map = fl.loadFile(filename);
	//get row and col size
	int rows = sizeof gm.map / sizeof gm.map[0]; 
	int cols = sizeof gm.map[0] / sizeof(int); 

	while (curPosx != cols && curPosy != rows)
	{
		//check for best move and then move there.
		// check the Point objects at the locations x-1, x+1 and y-1, y+1 from curPosx, curPosy
		//store those Point objects into an array and sort their fcosts to get the lowest possible fcost
		//then take that objects x and y values to set curPosx, curPosy to those values.
	}

    return 0;
}

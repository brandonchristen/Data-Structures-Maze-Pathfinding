//
//  main.cpp
//  data-structures-maze-pathfinding
//
//  Created by Alexander Cochrane on 2017-02-08.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    if (argc<1) {
        std::cout << "Please enter a filename." << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    
    return 0;
}

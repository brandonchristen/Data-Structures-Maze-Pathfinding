//
//  stack.hpp
//  data-structures-maze-pathfinding
//
//  Created by Alexander Cochrane on 2017-02-09.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include <stdexcept>

class Stack {
private:
    int length;
    char* items;
public:
    void push_back(char data);
    char pop_back();
    char peek();
    bool isEmpty();
    int size();
};
#endif /* stack_hpp */

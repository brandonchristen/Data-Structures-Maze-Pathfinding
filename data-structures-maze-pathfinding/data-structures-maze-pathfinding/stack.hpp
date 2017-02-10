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

#include "point.hpp"

class Stack {
private:
    int length;
    Point* items;
public:
    void push_back(Point data);
    Point pop_back();
    Point peek();
    bool isEmpty();
    int size();
};
#endif /* stack_hpp */

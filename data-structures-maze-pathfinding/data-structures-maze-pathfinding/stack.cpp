//
//  stack.cpp
//  data-structures-maze-pathfinding
//
//  Created by Alexander Cochrane on 2017-02-09.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include "stack.hpp"
void Stack::push_back(char data) {
    char* temp = new char[length];
    for (int i = 0; i < length; i++) {
        temp[i] = items[i];
    }
    length++;
    items = new char[length];
    for (int i = 0; i < length-1; i++) {
        items[i] = temp[i];
    }
    items[length-1] = data;
    delete[] temp;
}

char Stack::pop_back() {
    if (this->isEmpty()) {
        throw std::out_of_range("Stack is empty.");
    }
    char data = items[length-1];
    length--;
    char* temp = new char[length];
    for (int i = 0; i < length; i++) {
        temp[i] = items[i];
    }
    items = new char[length];
    for (int i = 0; i < length-1; i++) {
        items[i] = temp[i];
    }
    delete[] temp;
    
    return data;
}

char Stack::peek() {
    if (this->isEmpty()) {
        throw std::out_of_range("Stack is empty.");
    }
    return items[length-1];
}

bool Stack::isEmpty() {
    return (length == 0);
}

int Stack::size() {
    return length;
}

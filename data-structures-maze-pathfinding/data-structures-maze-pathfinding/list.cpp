//
//  list.cpp
//  data-structures-maze-pathfinding
//
//  Created by Alexander Cochrane on 2017-02-12.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include "list.hpp"

void List::push_back(Point* data) {
    Point** temp = new Point*[length];
    for (int i = 0; i < length; i++) {
        temp[i] = items[i];
    }
    length++;
    items = new Point*[length];
    for (int i = 0; i < length-1; i++) {
        items[i] = temp[i];
    }
    items[length-1] = data;
    delete[] temp;
}

Point* List::get(int index) {
    if (index > length-1) {
        char* message;
        sprintf(message,"Index %d out of range: %d",index,length-1);
        throw std::out_of_range(message);
    }
    return items[index];
}

void List::remove(Point* point) {
    Point** temp = new Point*[length];
    for (int i = 0; i < length; i++) {
        temp[i] = items[i];
    }
    length--;
    items = new Point*[length];
    int n = 0;
    for (int i = 0; i < length+1; i++) {
        if (&temp[i]==&point) continue;
        items[n] = temp[i];
        n++;
    }
    delete[] temp;
}

int List::size() {
    return length;
}

bool List::isEmpty() {
    return length==0;
}

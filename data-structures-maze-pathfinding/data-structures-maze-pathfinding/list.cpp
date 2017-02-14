//
//  list.cpp
//  data-structures-maze-pathfinding
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
    if (index > length-1 || index < 0) {
        char* message;
        sprintf(message,"Index %d out of range: %d-%d",index,0,length-1);
        throw std::out_of_range(message);
    }
    return items[index];
}

bool List::remove(Point* point) {
    if (length==0) return false;
    for (int i = 0; i < length; i++) {
        if (items[i]==point) {
            for (int j = i; j + 1 < length; j++) {
                items[j] = items[j+1];
            }
            length--;
            return true;
        }
    }
    return false;
}

int List::size() {
    return length;
}

bool List::isEmpty() {
    return length==0;
}

//
//  fileloader.cpp
//  data-structures-maze-pathfinding
//
//  Created by Alexander Cochrane on 2017-02-09.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include "fileloader.hpp"

//  takes a filename, and a pointer to a linked list
//  saves every line to a node in the linked list
char** FileLoader::loadFile(const std::string filename) {
    
    std::ifstream ifs(filename);
    char** map = new char*[0];
    rowLength = 0;
    numRows = 0;
    // if the file isn't open, the argument is invalid
    if (ifs.fail()) {
        throw std::invalid_argument("failed to load file");
    }
    bool b = true;
    // load every line of the file into the string, including whitespace.
    while (!ifs.eof()) {
        char** temp = new char*[numRows];
        for (int i = 0; i < numRows; i++) {
            temp[i] = map[i];
        }
        numRows++;
        map = new char*[numRows];
        for (int i = 0; i < numRows; i++) {
            map[i] = temp[i];
        }
        std::string tempstr;
        std::getline(ifs,tempstr);
        if (b) {
            b = !b;
            rowLength = (int) tempstr.length();
        }
        map[numRows-1] = &*tempstr.begin();
        
    }
    
    // close the stream
    ifs.close();
    return map;
}

//  takes a pointer to a linked list, and a filename
//  saves every node to the given file
void FileLoader::saveFile(char** map, std::string filename) {
    std::ofstream ofs(filename, std::fstream::out | std::fstream::trunc);
    
    // if the file isn't open, the argument is invalid
    if (ofs.fail()) throw std::invalid_argument("failed to save file");
    
    // output the string to file
    
    while (true) {
        // TODO: save map to file
    }
    
    // close the stream
    ofs.close();
}

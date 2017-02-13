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
Point*** FileLoader::loadFile(const char* filename) {

	std::ifstream ifs(filename);
	Point*** map = new Point**[0];
	rowLength = 0;
	numRows = 0;
	int x = 0;

	// if the file isn't open, the argument is invalid
	if (ifs.fail()) {
		throw std::invalid_argument("Invalid file name");
	}

	// load every line of the file into the string, including whitespace.
	while (!ifs.eof()) {
		int y = 0;
		std::string line;
		getline(ifs, line);

		if (line.length() > numRows) numRows = (int)line.length();

		for (char c : line) {
			Point* point = new Point(x, y, c, c != '+'&&c != '-');
			Point** plzwerk = &point;
			map[x][y] = *plzwerk;
			y++;
		}

		x++;
		if (y > rowLength) rowLength = y;
	}
	// close the stream
	ifs.close();
	return map;
}

//  takes a pointer to a linked list, and a filename
//  saves every node to the given file
void FileLoader::saveFile(Point*** map, Stack path, const char* filename) {
    char* outfilename;
    std::sprintf(outfilename,"%s%s",filename,"_solved");
    std::ofstream ofs(outfilename, std::fstream::out | std::fstream::trunc);
    
    // if the file isn't open, the argument is invalid
    if (ofs.fail()) throw std::invalid_argument("Invalid file name");
    
    // output the map to file
   const int rows = sizeof map / sizeof map[0];
    const int cols = sizeof map[0] / sizeof(Point*);
    char a[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            a[i][j] = map[i][j]->data;
        }
    }
    Point* point;
    while ((point = path.pop_back())!=NULL) {
        a[point->x][point->y] = '#';
    }
    
    // close the stream
    ofs.close();
}

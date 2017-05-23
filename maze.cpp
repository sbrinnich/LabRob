/* Copyright Selina Brinnich & Alexander Dietrich */

#include <fstream>
#include <iostream>
#include <string>
#include "maze.h"


void Maze::readFromFile(std::string filename) {
    std::ifstream file;
    ///open file
    file.open(filename, std::ios::out);
    char c;
    int x = 0, y = 0;

    ///go through file and read each character to put the maze into the vector
    while (!file.eof()){
        file.get(c);
        if(c != '\n')
        {
            lab[x][y] = 'c';
            x++;
        }
        ///if character is newline, go to next line in vector and reset x-axis
        else{
            x = 0;
            y ++;
        }
    }
}
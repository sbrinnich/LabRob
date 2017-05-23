/* Copyright Selina Brinnich & Alexander Dietrich */

#include "maze.h"

Maze::Maze() {}

void Maze::readFromFile(std::string filename) {}

char Maze::getPosition(int posx, int posy) {
    return ' ';
}

int Maze::isCrossing(int posx, int posy) {
    return -1;
}

int Maze::isDeadEnd(int posx, int posy) {
    return -1;
}

void Maze::defineStartAndGoal() {}
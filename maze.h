/* Copyright Selina Brinnich & Alexander Dietrich */

#ifndef U5_LABROB_MAZE_H
#define U5_LABROB_MAZE_H

#include <iostream>
#include <vector>

struct coordinates{
    int posx;
    int posy;
};

class Maze {
private:
    std::vector< std::vector <char> > lab;
    void defineStartAndGoal();
    coordinates start;
    coordinates goal;
    bool isProcessable = false;

public:
    Maze();
    Maze(const Maze &other);
    char getPosition(coordinates coords);
    bool isCrossing(coordinates coords);
    bool isDeadEnd(coordinates coords);
    void readFromFile(std::string filename);
    void setMaze(coordinates coords, char input);
    void printMaze();
    int getWidth();
    int getHeight();
    coordinates getStart();
    coordinates getGoal();
};

#endif //U5_LABROB_MAZE_H

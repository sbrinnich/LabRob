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

public:
    Maze();
    void readFromFile(std::string filename);
    char getPosition(coordinates coords);
    bool isCrossing(coordinates coords);
    bool isDeadEnd(coordinates coords);
    void printMaze();
    coordinates getStart();
    coordinates getGoal();


};

#endif //U5_LABROB_MAZE_H

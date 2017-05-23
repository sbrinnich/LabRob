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

public:
    Maze();
    void readFromFile(std::string filename);
    char getPosition(coordinates coords);
    int isCrossing(coordinates coords);
    int isDeadEnd(coordinates coords);

};

#endif //U5_LABROB_MAZE_H

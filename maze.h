/* Copyright Selina Brinnich & Alexander Dietrich */

#ifndef U5_LABROB_MAZE_H
#define U5_LABROB_MAZE_H

#include <iostream>
#include <vector>

class Maze {

private:
    std::vector< std::vector <char> > lab;
    void defineStartAndGoal();

public:
    Maze();
    void readFromFile(std::string filename);
    char getPosition(int posx, int posy);
    int isCrossing(int posx, int posy);
    int isDeadEnd(int posx, int posy);

};

#endif //U5_LABROB_MAZE_H

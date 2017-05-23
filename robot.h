/* Copyright Selina Brinnich & Alexander Dietrich */

#ifndef U5_LABROB_ROBOT_H
#define U5_LABROB_ROBOT_H

#include <iostream>
#include "maze.h"

class Robot {

private:
    int steps;
    std::string name;
    int finished;
    void checkFinished();

protected:
    Robot(std::string name, Maze* maze);
    int posx, posy, dir;
    const int NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3;
    virtual void doStep()=0;
    Maze* maze;

public:
    void startRobot();
    void printEndInfo();


};

#endif //U5_LABROB_ROBOT_H

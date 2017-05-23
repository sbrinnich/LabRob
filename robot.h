/* Copyright Selina Brinnich & Alexander Dietrich */

#ifndef U5_LABROB_ROBOT_H
#define U5_LABROB_ROBOT_H

#include <iostream>
#include "maze.h"

class Robot {

private:
    std::string name;
    int steps;
    int finished;
    void checkFinished();

protected:
    Maze* maze;
    Robot(std::string name, Maze* maze);
    int posx, posy, dir;
    const int NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3;
    virtual void doStep()=0;

public:
    void startRobot();
    void printEndInfo();
    virtual ~Robot();

};

#endif //U5_LABROB_ROBOT_H

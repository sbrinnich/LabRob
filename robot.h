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
    int dir;
    coordinates coords;
    static const int NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3, LEFT = 4, RIGHT = 5, FORWARD = 6;
    virtual void doStep()=0;
    coordinates calculateNextPos(int move_to);
    void turn(int turn_dir);

public:
    void startRobot();
    void printEndInfo();
    virtual ~Robot();

};

#endif //U5_LABROB_ROBOT_H

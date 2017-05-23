/* Copyright Selina Brinnich & Alexander Dietrich */

#include "robot.h"

Robot::Robot(std::string name, Maze* maze) : name(name), maze(maze), steps(0), finished(0) {}

void Robot::startRobot() {
    while(!finished){
        doStep();
        checkFinished();
    }
    printEndInfo();
}

void Robot::printEndInfo() {
    std::cout << name << " found an exit to the maze in " << steps << " steps!" << std::endl;
}

void Robot::checkFinished() {

}
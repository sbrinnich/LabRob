/* Copyright Selina Brinnich & Alexander Dietrich */

#include "robot.h"

Robot::Robot(std::string name, Maze* maze) : name(name), steps(0), finished(0), maze(maze), coords(maze->getStart()) {
    if(coords.posy == 0){
        dir = SOUTH;
    }else if(coords.posx == 0){
        dir = EAST;
    }else if(coords.posy == maze->getHeight()-1){
        dir = NORTH;
    }else if(coords.posx == maze->getWidth()-1){
        dir = WEST;
    }
}

Robot::~Robot(){}

void Robot::startRobot() {
    while(!finished){
        doStep();
        //std::cout << "Testy " << steps << ", " << coords.posx << ", " << coords.posy << std::endl;
        steps++;
        checkFinished();
    }
    printEndInfo();
}

void Robot::printEndInfo() {
    std::cout << "Robot " << name << " found an exit to the maze in " << steps << " steps!" << std::endl;
}

void Robot::checkFinished() {
    if(maze->getGoal().posx == coords.posx && maze->getGoal().posy == coords.posy){
        finished = true;
    }
}
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
        steps++;
        checkFinished();
    }
}

void Robot::printEndInfo() {
    std::cout << "Robot " << name << " found an exit to the maze in " << steps << " steps!" << std::endl;
}

void Robot::checkFinished() {
    if(maze->getGoal().posx == coords.posx && maze->getGoal().posy == coords.posy){
        finished = true;
    }
}

void Robot::turn(int turn_dir) {
    switch(turn_dir){
        case LEFT:
            dir--;
            if(dir < 0){
                dir = 3;
            }
            break;
        case RIGHT:
            dir++;
            if(dir > 3){
                dir = 0;
            }
            break;
    }
}

coordinates Robot::calculateNextPos(int move_to) {
    coordinates c = coords;
    switch(move_to){
        case LEFT:
            switch(dir) {
                case NORTH:
                    c.posx--;
                    break;
                case EAST:
                    c.posy--;
                    break;
                case SOUTH:
                    c.posx++;
                    break;
                case WEST:
                    c.posy++;
                    break;
            }
            break;
        case RIGHT:
            switch(dir){
                case NORTH:
                    c.posx++;
                    break;
                case EAST:
                    c.posy++;
                    break;
                case SOUTH:
                    c.posx--;
                    break;
                case WEST:
                    c.posy--;
                    break;
            }
            break;
        case FORWARD:
            switch(dir){
                case NORTH:
                    c.posy--;
                    break;
                case EAST:
                    c.posx++;
                    break;
                case SOUTH:
                    c.posy++;
                    break;
                case WEST:
                    c.posx--;
                    break;
            }
            break;
        case BACKWARDS:
            switch(dir){
                case NORTH:
                    c.posy++;
                    break;
                case EAST:
                    c.posx--;
                    break;
                case SOUTH:
                    c.posy--;
                    break;
                case WEST:
                    c.posx++;
                    break;
            }
            break;
    }
    return c;
}
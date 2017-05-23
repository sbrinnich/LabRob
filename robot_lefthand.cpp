/* Copyright Selina Brinnich & Alexander Dietrich */

#include "robot_lefthand.h"

LeftHand::LeftHand(Maze *maze) : Robot("Left Hand", maze){}

LeftHand::~LeftHand() {}

void LeftHand::doStep() {
    coordinates left = calculateNextPos(Robot::LEFT);
    coordinates forward = calculateNextPos(Robot::FORWARD);
    coordinates right = calculateNextPos(Robot::RIGHT);
    if(maze->getPosition(left) == ' '){
        turn(Robot::LEFT);
        coords = left;
    }else if(maze->getPosition(forward) == ' '){
        coords = forward;
    }else if(maze->getPosition(right) == ' '){
        turn(Robot::RIGHT);
        coords = right;
    }else{
        turn(Robot::LEFT);
        turn(Robot::LEFT);
        coords = calculateNextPos(Robot::FORWARD);
    }
}

void LeftHand::turn(int turn_dir) {
    switch(turn_dir){
        case Robot::LEFT:
            dir--;
            if(dir < 0){
                dir = 3;
            }
            break;
        case Robot::RIGHT:
            dir++;
            if(dir > 3){
                dir = 0;
            }
            break;
    }
}

coordinates LeftHand::calculateNextPos(int move_to) {
    coordinates c = coords;
    switch(move_to){
        case Robot::LEFT:
            switch(dir) {
                case Robot::NORTH:
                    c.posx--;
                    break;
                case Robot::EAST:
                    c.posy--;
                    break;
                case Robot::SOUTH:
                    c.posx++;
                    break;
                case Robot::WEST:
                    c.posy++;
                    break;
            }
            break;
        case Robot::RIGHT:
            switch(dir){
                case Robot::NORTH:
                    c.posx++;
                    break;
                case Robot::EAST:
                    c.posy++;
                    break;
                case Robot::SOUTH:
                    c.posx--;
                    break;
                case Robot::WEST:
                    c.posy--;
                    break;
            }
            break;
        case Robot::FORWARD:
            switch(dir){
                case Robot::NORTH:
                    c.posy--;
                    break;
                case Robot::EAST:
                    c.posx++;
                    break;
                case Robot::SOUTH:
                    c.posy++;
                    break;
                case Robot::WEST:
                    c.posx--;
                    break;
            }
            break;
    }
    return c;
}
/* Copyright Selina Brinnich & Alexander Dietrich */

#include "robot_lefthand.h"

LeftHand::LeftHand(Maze *maze) : Robot("Left Hand", maze){}

LeftHand::~LeftHand() {}

void LeftHand::doStep() {
    coordinates left = calculateNextPos(LEFT);
    coordinates forward = calculateNextPos(FORWARD);
    coordinates right = calculateNextPos(RIGHT);

    if(maze->getPosition(left) == ' '){
        turn(LEFT);
        coords = left;
    }else if(maze->getPosition(forward) == ' '){
        coords = forward;
    }else if(maze->getPosition(right) == ' '){
        turn(RIGHT);
        coords = right;
    }else{
        turn(LEFT);
        turn(LEFT);
        coords = calculateNextPos(FORWARD);
    }
}

void LeftHand::turn(int turn_dir) {
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

coordinates LeftHand::calculateNextPos(int move_to) {
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
    }
    return c;
}
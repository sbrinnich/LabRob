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
/* Copyright Selina Brinnich & Alexander Dietrich */

#include "robot_lefthand.h"

LeftHand::LeftHand(Maze *maze) : Robot("Left Hand", maze){}

LeftHand::~LeftHand() {}

void LeftHand::doStep() {
    // Go left if possible
    coordinates c = calculateNextPos(LEFT);
    if(maze->getPosition(c) == ' '){
        turn(LEFT);
        coords = c;
        return;
    }

    // Go forward if possible
    c = calculateNextPos(FORWARD);
    if(maze->getPosition(c) == ' '){
        coords = c;
        return;
    }

    // Go right if possible
    c = calculateNextPos(RIGHT);
    if(maze->getPosition(c) == ' '){
        turn(RIGHT);
        coords = c;
        return;
    }

    // Go back
    turn(LEFT);
    turn(LEFT);
    coords = calculateNextPos(FORWARD);
}
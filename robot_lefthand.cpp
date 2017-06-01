/* Copyright Selina Brinnich & Alexander Dietrich */

#include "robot_lefthand.h"

LeftHand::LeftHand(Maze *maze) : Robot("Left Hand", maze){
    this->maze = new Maze(*maze);
    maze->setMaze(coords, '.');
}

LeftHand::~LeftHand() {
    delete maze;
}

bool LeftHand::doStep() {
    if (lastCoords.posx == coords.posx && lastCoords.posy == coords.posy) {
        return true;
    } else {
        lastCoords = coords;
        // Go left if possible
        coordinates c = calculateNextPos(LEFT);
        if (maze->getPosition(c) == ' ' || maze->getPosition(c) == '.') {
            turn(LEFT);
            coords = c;
            maze->setMaze(coords, '.');
            return false;
        }

        // Go forward if possible
        c = calculateNextPos(FORWARD);
        if (maze->getPosition(c) == ' ' || maze->getPosition(c) == '.') {
            coords = c;
            maze->setMaze(coords, '.');
            return false;
        }

        // Go right if possible
        c = calculateNextPos(RIGHT);
        if (maze->getPosition(c) == ' ' || maze->getPosition(c) == '.') {
            turn(RIGHT);
            coords = c;
            maze->setMaze(coords, '.');
            return false;
        }

        // Go back
        turn(LEFT);
        turn(LEFT);
        coords = calculateNextPos(FORWARD);
        maze->setMaze(coords, '.');
        return false;
    }
}
/* Copyright Selina Brinnich & Alexander Dietrich */

#include "robot_tremaux.h"

Tremaux::Tremaux(Maze *maze) : Robot("Tremaux", maze){
    this->maze = new Maze(*maze);

    for(int i = 0; i < maze->getWidth(); i++){
        markings.push_back(std::vector<int>());
        for(int j = 0; j < maze->getHeight(); j++){
            markings.at(i).push_back(0);
        }
    }
    markings.at(coords.posx).at(coords.posy) = 2;
}

Tremaux::~Tremaux() {
    delete maze;
}

bool Tremaux::doStep() {
    if (coords.posx == lastCoords.posx && coords.posy == lastCoords.posy) {
        return true;
    } else {
        lastCoords = coords;
        if (maze->isCrossing(coords)) {
            coordinates back = calculateNextPos(BACKWARDS);
            if (!isVisited() || markings.at(back.posx).at(back.posy) >= 2) {
                int minmarkingsdir = getMinMarkingsDir();
                if (minmarkingsdir == -1) {
                    // Go back
                    turn(LEFT);
                    turn(LEFT);
                    coords = calculateNextPos(FORWARD);
                } else {
                    // Direction without 2 markings found, go there
                    switch (minmarkingsdir) {
                        case LEFT:
                            turn(LEFT);
                            break;
                        case RIGHT:
                            turn(RIGHT);
                            break;
                    }
                    coords = calculateNextPos(FORWARD);
                }
            } else {
                // Go back
                turn(LEFT);
                turn(LEFT);
                coords = calculateNextPos(FORWARD);
            }
        } else {
            coordinates forward = calculateNextPos(FORWARD);
            coordinates right = calculateNextPos(RIGHT);
            coordinates left = calculateNextPos(LEFT);
            if (maze->getPosition(right) == ' ' || maze->getPosition(right) == '.') {
                // Go right if possible
                turn(RIGHT);
                coords = right;
            } else if (maze->getPosition(left) == ' ' || maze->getPosition(left) == '.') {
                // Go left if possible
                turn(LEFT);
                coords = left;
            } else if (maze->getPosition(forward) == ' ' || maze->getPosition(forward) == '.') {
                // Go forward if possible
                coords = forward;
            } else {
                // Go back
                turn(LEFT);
                turn(LEFT);
                coords = calculateNextPos(FORWARD);
            }
        }

        markings.at(coords.posx).at(coords.posy)++;

        if (maze->isDeadEnd(coords)) {
            markings.at(coords.posx).at(coords.posy)++;
        }

        maze->setMaze(coords, '.');

        return false;
    }
}

int Tremaux::getMinMarkingsDir() {
    int minmarkings = 2;
    int ret = -1;
    coordinates c = calculateNextPos(RIGHT);
    if((maze->getPosition(c) == ' ' || maze->getPosition(c) == '.') && markings.at(c.posx).at(c.posy) < minmarkings){
        minmarkings = markings.at(c.posx).at(c.posy);
        ret = RIGHT;
    }
    c = calculateNextPos(LEFT);
    if((maze->getPosition(c) == ' ' || maze->getPosition(c) == '.') && markings.at(c.posx).at(c.posy) < minmarkings){
        minmarkings = markings.at(c.posx).at(c.posy);
        ret = LEFT;
    }
    c = calculateNextPos(FORWARD);
    if((maze->getPosition(c) == ' ' || maze->getPosition(c) == '.') && markings.at(c.posx).at(c.posy) < minmarkings){
        minmarkings = markings.at(c.posx).at(c.posy);
        ret = FORWARD;
    }

    if(ret == -1){
        coordinates c = calculateNextPos(RIGHT);
        if((maze->getPosition(c) == ' ' || maze->getPosition(c) == '.') && maze->isCrossing(c)){
            return RIGHT;
        }
        c = calculateNextPos(LEFT);
        if((maze->getPosition(c) == ' ' || maze->getPosition(c) == '.') && maze->isCrossing(c)){
            return LEFT;
        }
        c = calculateNextPos(FORWARD);
        if((maze->getPosition(c) == ' ' || maze->getPosition(c) == '.') && maze->isCrossing(c)){
            return FORWARD;
        }
    }

    return ret;
}

bool Tremaux::isVisited() {
    coordinates c = calculateNextPos(RIGHT);
    if((maze->getPosition(c) == ' ' || maze->getPosition(c) == '.') && markings.at(c.posx).at(c.posy) > 0){
        return true;
    }
    c = calculateNextPos(LEFT);
    if((maze->getPosition(c) == ' ' || maze->getPosition(c) == '.') && markings.at(c.posx).at(c.posy) > 0){
        return true;
    }
    c = calculateNextPos(FORWARD);
    if((maze->getPosition(c) == ' ' || maze->getPosition(c) == '.') && markings.at(c.posx).at(c.posy) > 0){
        return true;
    }
    return false;
}

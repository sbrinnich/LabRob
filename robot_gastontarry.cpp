/* Copyright Selina Brinnich & Alexander Dietrich */

#include "robot_gastontarry.h"

GastonTarry::GastonTarry(Maze* maze) : Robot("Gaston Tarry", maze){
    width = maze->getWidth();
    height = maze->getHeight();

    this->maze = new Maze(*maze);

    map = new int* [width];

    for (int i = 0; i < width; ++i) {
        map[i] = new int[height];
    }

    for (int j = 0; j < width; ++j) {
        for (int i = 0; i < height; ++i) {
            map[j][i] = 0;
        }
    }
}

GastonTarry::~GastonTarry() {
    for (int i = 0; i < width; ++i) {
        delete[] map[i];
    }
    delete[] map;
    delete maze;
}

bool GastonTarry::doStep() {
    if (coords.posx == lastCoords.posx && coords.posy == lastCoords.posy) {
        return true;
    } else {
        lastCoords = coords;
        maze->setMaze(coords, '.');
        coordinates left = calculateNextPos(LEFT);
        coordinates right = calculateNextPos(RIGHT);
        coordinates forward = calculateNextPos(FORWARD);
        coordinates backwards = calculateNextPos(BACKWARDS);


        if (maze->isCrossing(coords)) {
            if (map[left.posx][left.posy] == 0 && map[right.posx][right.posy] == 0 &&
                map[forward.posx][forward.posy] == 0) {
                map[backwards.posx][backwards.posy] = BACK;
            }
            if ((maze->getPosition(left) == ' ' || maze->getPosition(left) == '.') &&
                map[left.posx][left.posy] != STOP && map[left.posx][left.posy] != BACK) {
                turn(LEFT);
                coords = left;
                map[coords.posx][coords.posy] = STOP;
            } else if ((maze->getPosition(right) == ' ' || maze->getPosition(right) == '.') &&
                       map[right.posx][right.posy] != STOP && map[right.posx][right.posy] != BACK) {
                turn(RIGHT);
                coords = right;
                map[coords.posx][coords.posy] = STOP;
            } else if ((maze->getPosition(forward) == ' ' || maze->getPosition(forward) == '.') &&
                       map[forward.posx][forward.posy] != STOP && map[forward.posx][forward.posy] != BACK) {
                coords = forward;
                map[coords.posx][coords.posy] = STOP;
            } else if ((maze->getPosition(left) == ' ' || maze->getPosition(left) == '.') &&
                       map[left.posx][left.posy] == BACK) {
                turn(LEFT);
                coords = left;
                map[coords.posx][coords.posy] = STOP;
            } else if ((maze->getPosition(right) == ' ' || maze->getPosition(right) == '.') &&
                       map[right.posx][right.posy] == BACK) {
                turn(RIGHT);
                coords = right;
                map[coords.posx][coords.posy] = STOP;
            } else if ((maze->getPosition(forward) == ' ' || maze->getPosition(forward) == '.') &&
                       map[forward.posx][forward.posy] == BACK) {
                coords = forward;
                map[coords.posx][coords.posy] = STOP;
            }
        } else {
            if (maze->getPosition(right) == ' ' || maze->getPosition(right) == '.') {
                turn(RIGHT);
                coords = right;
            } else if (maze->getPosition(left) == ' ' || maze->getPosition(left) == '.') {
                turn(LEFT);
                coords = left;
            } else if (maze->getPosition(forward) == ' ' || maze->getPosition(forward) == '.') {
                coords = forward;
            } else {
                turn(LEFT);
                turn(LEFT);
                coords = calculateNextPos(FORWARD);
            }
        }

        maze->setMaze(coords, '.');
        return false;
    }
}
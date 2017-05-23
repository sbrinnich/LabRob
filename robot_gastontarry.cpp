/* Copyright Selina Brinnich & Alexander Dietrich */

#include "robot_gastontarry.h"

GastonTarry::GastonTarry(Maze* maze) : Robot("Gaston Tarry", maze){
    width = maze->getWidth();
    height = maze->getHeight();

    map = new int* [width];

    for (int i = 0; i < width; ++i) {
        map[i] = new int[height];
    }
}

GastonTarry::~GastonTarry() {
    for (int i = 0; i < width; ++i) {
        delete[] map[i];
    }
    delete[] map;
}

void GastonTarry::doStep() {}
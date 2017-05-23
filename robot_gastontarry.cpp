/* Copyright Selina Brinnich & Alexander Dietrich */

#include "robot_gastontarry.h"

GastonTarry::GastonTarry(Maze* maze) : Robot("Gaston Tarry", maze){
    width = maze->getWidth();
    height = maze->getHeight();

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
}

void GastonTarry::doStep() {
    std::cout << coords.posx << coords.posy << std::endl;
    coordinates left = calculateNextPos(LEFT);
    coordinates right = calculateNextPos(RIGHT);
    coordinates forward = calculateNextPos(FORWARD);
    coordinates backwards = calculateNextPos(BACKWARDS);


    if(maze->isCrossing(coords)){
        if(map[left.posx][left.posy] == 0 &&  map[right.posx][right.posy] == 0 && map[forward.posx][forward.posy] == 0){
            map[backwards.posx][backwards.posy] = BACK;
            std::cout << "set back on x:" << backwards.posx  << " y:" << backwards.posy << std::endl;
        }
        std::cout << "kreuzung" << std::endl;
        std::cout << map[left.posx][left.posy] << std::endl;
        std::cout << map[right.posx][right.posy] << std::endl;
        std::cout << map[forward.posx][forward.posy] << std::endl;
        if(maze->getPosition(left) == ' ' && map[left.posx][left.posy] != STOP && map[left.posx][left.posy] != BACK){
            std::cout << "links" << std::endl;
            turn(LEFT);
            coords = left;
            map[coords.posx][coords.posy] = STOP;
            std::cout << "set stop on x:" << coords.posx  << " y:" << coords.posy << std::endl;
        }else if(maze->getPosition(right) == ' ' && map[right.posx][right.posy] != STOP && map[right.posx][right.posy] != BACK){
            std::cout << "rechts" << std::endl;
            turn(RIGHT);
            coords = right;
            map[coords.posx][coords.posy] = STOP;
            std::cout << "set stop on x:" << coords.posx  << " y:" << coords.posy << std::endl;
        }else if(maze->getPosition(forward) == ' ' && map[forward.posx][forward.posy] != STOP && map[forward.posx][forward.posy] != BACK){
            std::cout << "gerade" << std::endl;
            coords = forward;
            map[coords.posx][coords.posy] = STOP;
            std::cout << "set stop on x:" << coords.posx  << " y:" << coords.posy << std::endl;
        }else if(maze->getPosition(left) == ' ' && map[left.posx][left.posy] == BACK){
            std::cout << "links" << std::endl;
            turn(LEFT);
            coords = left;
            map[coords.posx][coords.posy] = STOP;
            std::cout << "set stop on x:" << coords.posx  << " y:" << coords.posy << std::endl;
        }else if(maze->getPosition(right) == ' ' && map[right.posx][right.posy] == BACK){
            std::cout << "rechts" << std::endl;
            turn(RIGHT);
            coords = right;
            map[coords.posx][coords.posy] = STOP;
            std::cout << "set stop on x:" << coords.posx  << " y:" << coords.posy << std::endl;
        }else if(maze->getPosition(forward) == ' ' && map[forward.posx][forward.posy] == BACK){
            std::cout << "gerade" << std::endl;
            coords = forward;
            map[coords.posx][coords.posy] = STOP;
            std::cout << "set stop on x:" << coords.posx  << " y:" << coords.posy << std::endl;
        }
    }else{
        std::cout << "keine kreuzung " << std::endl;
        if(maze->getPosition(left) == ' '){
            std::cout << "links 2" << std::endl;
            turn(LEFT);
            coords = left;

        }else if(maze->getPosition(right) == ' '){
            std::cout << "rechts 2" << std::endl;
            turn(RIGHT);
            coords = right;

        }else if(maze->getPosition(forward) == ' '){
            std::cout << "gerade 2" << std::endl;
            coords = forward;

        }else{
            std::cout << "drehung 2" << std::endl;
            turn(LEFT);
            turn(LEFT);
            coords = calculateNextPos(FORWARD);
        }
    }
    std::cout << std::endl << std::endl;
}
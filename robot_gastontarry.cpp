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

void GastonTarry::doStep() {
    //std::cout << coords.posx << coords.posy << std::endl;
    coordinates left = calculateNextPos(LEFT);
    coordinates right = calculateNextPos(RIGHT);
    coordinates forward = calculateNextPos(FORWARD);

    if(maze->isCrossing(coords)){
        //std::cout << "kreuzung" << std::endl;
        //std::cout << map[left.posx][left.posy] << std::endl;
        //std::cout << map[right.posx][right.posy] << std::endl;
        //std::cout << map[forward.posx][forward.posy] << std::endl;
        if(maze->getPosition(left) == ' ' && map[left.posx][left.posy] != STOP && map[left.posx][left.posy] != BACK){
            //std::cout << "links" << std::endl;
            turn(LEFT);
            coords = left;
            map[coords.posx][coords.posy] = STOP;
        }else if(maze->getPosition(right) == ' ' && map[right.posx][right.posy] != STOP && map[right.posx][right.posy] != BACK){
            //std::cout << "rechts" << std::endl;
            turn(RIGHT);
            coords = right;
            map[coords.posx][coords.posy] = STOP;
        }else if(maze->getPosition(forward) == ' ' && map[forward.posx][forward.posy] != STOP && map[forward.posx][forward.posy] != BACK){
            //std::cout << "gerade" << std::endl;
            coords = forward;
            map[coords.posx][coords.posy] = STOP;
        }else if(maze->getPosition(left) == ' ' && map[left.posx][left.posy] == BACK){
            //std::cout << "links" << std::endl;
            turn(LEFT);
            coords = left;
            map[coords.posx][coords.posy] = STOP;
        }else if(maze->getPosition(right) == ' ' && map[right.posx][right.posy] == BACK){
            //std::cout << "rechts" << std::endl;
            turn(RIGHT);
            coords = right;
            map[coords.posx][coords.posy] = STOP;
        }else if(maze->getPosition(forward) == ' ' && map[forward.posx][forward.posy] == BACK){
            //std::cout << "gerade" << std::endl;
            coords = forward;
            map[coords.posx][coords.posy] = STOP;
        }else{
            //std::cout << "drehung" << std::endl;
            turn(LEFT);
            turn(LEFT);
            coords = calculateNextPos(FORWARD);
            map[coords.posx][coords.posy] = STOP;
        }
    }else{
        //std::cout << "keine kreuzung " << std::endl;
        if(maze->getPosition(left) == ' '){
            //std::cout << "links 2" << std::endl;
            turn(LEFT);
            coords = left;

        }else if(maze->getPosition(right) == ' '){
            //std::cout << "rechts 2" << std::endl;
            turn(RIGHT);
            coords = right;

        }else if(maze->getPosition(forward) == ' '){
            //std::cout << "gerade 2" << std::endl;
            coords = forward;

        }else{
            //std::cout << "drehung 2" << std::endl;
            turn(LEFT);
            turn(LEFT);
            coords = calculateNextPos(FORWARD);
        }
    }
    //std::cout << std::endl << std::endl;
}
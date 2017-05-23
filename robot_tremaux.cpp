/* Copyright Selina Brinnich & Alexander Dietrich */

#include "robot_tremaux.h"

Tremaux::Tremaux(Maze *maze) : Robot("Tremaux", maze){
    for(int i = 0; i < maze->getWidth(); i++){
        markings.push_back(std::vector<int>());
        for(int j = 0; j < maze->getHeight(); j++){
            markings.at(i).push_back(0);
        }
    }
}

Tremaux::~Tremaux() {}

void Tremaux::doStep() {

}
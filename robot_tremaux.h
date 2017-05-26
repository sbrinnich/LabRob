/* Copyright Selina Brinnich & Alexander Dietrich */

#ifndef U5_LABROB_ROBOT_TREMAUX_H
#define U5_LABROB_ROBOT_TREMAUX_H

#include "robot.h"

class Tremaux : public Robot{
public:
    Tremaux(Maze* maze);
    ~Tremaux();

protected:
    bool doStep();

private:
    std::vector< std::vector<int> > markings;
    coordinates lastCoords;
    int getMinMarkingsDir();
    bool isVisited();
};

#endif //U5_LABROB_ROBOT_TREMAUX_H

/* Copyright Selina Brinnich & Alexander Dietrich */

#ifndef U5_LABROB_ROBOT_GASTONTARRY_H
#define U5_LABROB_ROBOT_GASTONTARRY_H

#include "robot.h"

class GastonTarry : public Robot {
public:
    GastonTarry(Maze* maze);
    ~GastonTarry();

protected:
    bool doStep();


private:
    int** map;
    int height;
    int width;
    coordinates lastCoords;
    static const int STOP = 2, BACK = 1;
};

#endif //U5_LABROB_ROBOT_GASTONTARRY_H

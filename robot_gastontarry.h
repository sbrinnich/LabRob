/* Copyright Selina Brinnich & Alexander Dietrich */

#ifndef U5_LABROB_ROBOT_GASTONTARRY_H
#define U5_LABROB_ROBOT_GASTONTARRY_H

#include "robot.h"

class GastonTarry : public Robot {
public:
    GastonTarry(Maze* maze);
    ~GastonTarry();

protected:
    void doStep();
};

#endif //U5_LABROB_ROBOT_GASTONTARRY_H

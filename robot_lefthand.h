/* Copyright Selina Brinnich & Alexander Dietrich */

#ifndef U5_LABROB_ROBOT_LEFTHAND_H
#define U5_LABROB_ROBOT_LEFTHAND_H

#include "robot.h"

class LeftHand : public Robot {
public:
    LeftHand(Maze* maze);
    ~LeftHand();

protected:
    bool doStep();

private:
    coordinates lastCoords;
};

#endif //U5_LABROB_ROBOT_LEFTHAND_H

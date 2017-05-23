/* Copyright Selina Brinnich & Alexander Dietrich */

#ifndef U5_LABROB_ROBOT_TREMAUX_H
#define U5_LABROB_ROBOT_TREMAUX_H

#include "robot.h"

class Tremaux : public Robot{
public:
    Tremaux(Maze* maze);
    ~Tremaux();

protected:
    void doStep();

private:
    std::vector< std::vector<int> > markings;
};

#endif //U5_LABROB_ROBOT_TREMAUX_H

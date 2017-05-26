//
// Created by Alexander Dietrich on 26.05.2017.
//

#ifndef U5_LABROB_ROBOT_FILL_DEADEND_H
#define U5_LABROB_ROBOT_FILL_DEADEND_H

#include <vector>
#include "maze.h"
#include "robot.h"

class fill_deadend : public Robot {
private:
    int startDir;

public:
    fill_deadend(Maze *maze);
    ~fill_deadend();

protected:
    void doStep();

};


#endif //U5_LABROB_ROBOT_FILL_DEADEND_H

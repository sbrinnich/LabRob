//
// Created by Alexander Dietrich on 26.05.2017.
//

#include "robot_fill_deadend.h"

fill_deadend::fill_deadend(Maze *maze) : Robot("FillDeadend", maze) {
    this->maze = new Maze(*maze);
    this->startDir = dir;
}

fill_deadend::~fill_deadend() {
    delete maze;
}

void fill_deadend::doStep() {
    coordinates forward = calculateNextPos(FORWARD);
    coordinates backwards = calculateNextPos(BACKWARDS);
    coordinates right = calculateNextPos(RIGHT);
    coordinates left = calculateNextPos(LEFT);

    if(maze->isCrossing(coords)) {
        if (maze->getPosition(right) == ' ') {
            maze->setMaze(coords, '.');
            turn(RIGHT);
            coords = right;
            return;
        } else if (maze->getPosition(forward) == ' ') {
            maze->setMaze(coords, '.');
            coords = forward;
            return;
        } else if (maze->getPosition(left) == ' ') {
            maze->setMaze(coords, '.');
            turn(LEFT);
            coords = left;
            return;
        }
    }
    if ((maze->getPosition(right) == ' ' || maze->getPosition(right) == '.') && !maze->isDeadEnd(coords)) {
        maze->setMaze(coords, '.');
        turn(RIGHT);
        coords = right;
        return;
    } else if ((maze->getPosition(forward) == ' ' || maze->getPosition(forward) == '.') && !maze->isDeadEnd(coords)) {
        maze->setMaze(coords, '.');
        coords = forward;
        return;
    } else if ((maze->getPosition(left) == ' ' || maze->getPosition(left) == '.') && !maze->isDeadEnd(coords)) {
        maze->setMaze(coords, '.');
        turn(LEFT);
        coords = left;
        return;
    }
    if (maze->isDeadEnd(coords)) {
        if(maze->getStart().posx == coords.posx && maze->getStart().posy == coords.posy ){
            if(dir != startDir){
                dir = startDir;
                forward = calculateNextPos(FORWARD);
            }
            coords = forward;
            return;
        }else{
            maze->setMaze(coords, 'x');
            if(maze->getPosition(right) == '.'){
                turn(LEFT);
                backwards = calculateNextPos(BACKWARDS);
            }else if(maze->getPosition(left) == '.'){
                turn(RIGHT);
                backwards = calculateNextPos(BACKWARDS);
            }
            coords = backwards;
        }
    }
}

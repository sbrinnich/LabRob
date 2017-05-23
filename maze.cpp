/* Copyright Selina Brinnich & Alexander Dietrich */

#include <fstream>
#include <iostream>
#include "maze.h"

Maze::Maze() {}

void Maze::readFromFile(std::string filename) {
    std::ifstream file;
    ///open file
    file.open(filename, std::ios::out);
    char c;
    unsigned int x = 0;
    unsigned int y = 0;
    int firstline = 1;

    ///go through file and read each character to put the maze into the vector
    while (!file.eof()){
        file.get(c);
        if(c != '\n')
        {
            if(firstline){
                lab.push_back(std::vector<char>());
            }
            lab[x].push_back(c);
            ///std::cout << lab.at(x).at(y) << std::endl;
            x++;
        }
        ///if character is newline, go to next line in vector and reset x-axis
        else{
            firstline = 0;
            x = 0;
            y ++;
        }
    }
    ///std::cout << "testy 3" << std::endl;
    file.close();

    defineStartAndGoal();
}

void Maze::defineStartAndGoal() {
    unsigned int x = lab.size();
    unsigned int y = 0;
    y = lab[y].size();
    bool check = false;
    bool check_finish = false;
    for (unsigned int i = 0; i < x; ++i) {
        if(!check && lab.at(i).at(0) == ' '){
            lab.at(i).at(0) = 's';
            check = true;
        }else if(check && lab.at(i).at(0) == ' '){
            lab.at(i).at(0) = 'g';
            check_finish = true;
        }
    }
    if(!check_finish){
        for (unsigned int i = 0; i < y; ++i) {
            if(!check && lab.at(x-1).at(i) == ' '){
                lab.at(x-1).at(i) = 's';
                check = true;
            }else if(check && lab.at(x-1).at(i) == ' '){
                lab.at(x-1).at(i) = 'g';
                check_finish = true;
            }
        }
    }
    if(!check_finish){
        for (unsigned int i = 0; i < x; ++i) {
            if(!check && lab.at(i).at(y-1) == ' '){
                lab.at(i).at(y-1) = 's';
                check = true;
            }else if(check && lab.at(i).at(y-1) == ' '){
                lab.at(i).at(y-1) = 'g';
                check_finish = true;
            }
        }
    }
    if(!check_finish){
        for (unsigned int i = 0; i < y; ++i) {
            if(!check && lab.at(0).at(i) == ' '){
                lab.at(0).at(i) = 's';
                check = true;
            }else if(check && lab.at(0).at(i) == ' '){
                lab.at(0).at(i) = 'g';
            }
        }
    }
}

char Maze::getPosition(coordinates coords) {
    return lab[coords.posx][coords.posy];
}

bool Maze::isCrossing(coordinates coords) {
    int count_directions = 0;
    if(lab[coords.posx + 1][coords.posy] == ' '){
        count_directions ++;
    }
    if(lab[coords.posx][coords.posy + 1] == ' '){
        count_directions ++;
    }
    if(lab[coords.posx - 1][coords.posy] == ' '){
        count_directions ++;
    }
    if(lab[coords.posx][coords.posy - 1] == ' '){
        count_directions ++;
    }
    if(count_directions > 2){
        return true;
    }else{
        return false;
    }
}

bool Maze::isDeadEnd(coordinates coords) {
    int count_directions = 0;
    if(lab[coords.posx +1][coords.posy] != ' '){
        count_directions ++;
    }
    if(lab[coords.posx][coords.posy + 1] != ' '){
        count_directions ++;
    }
    if(lab[coords.posx -1][coords.posy] != ' '){
        count_directions ++;
    }
    if(lab[coords.posx][coords.posy -1] != ' '){
        count_directions ++;
    }
    if(count_directions == 1){
        return true;
    }else{
        return false;
    }
}

void Maze::printMaze() {
    for (unsigned int y = 0; y < lab.size(); ++y) {
        for (unsigned int x = 0; x < lab[0].size(); ++x) {
            std::cout << lab.at(x).at(y);
        }
        std::cout << std::endl;

    }
}

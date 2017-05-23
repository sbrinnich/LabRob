/* Copyright Selina Brinnich & Alexander Dietrich */

#include <fstream>
#include <iostream>
#include <string>
#include "maze.h"


void Maze::readFromFile(std::string filename) {
    std::ifstream file;
    ///open file
    file.open(filename, std::ios::out);
    char c;
    int x = 0, y = 0;

    ///go through file and read each character to put the maze into the vector
    while (!file.eof()){
        file.get(c);
        if(c != '\n')
        {
            lab[x][y] = 'c';
            x++;
        }
        ///if character is newline, go to next line in vector and reset x-axis
        else{
            x = 0;
            y ++;
        }
    }
}

void Maze::defineStartAndGoal() {
    bool check = false;
    bool check_finish = false;
    for (unsigned int i = 0; i < lab.size(); ++i) {
        if(!check && lab[i][0] == ' '){
            lab[i][0] = 's';
            check = true;
        }else if(check && lab[i][0] == ' '){
            lab[i][0] = 'g';
            check_finish = true;
        }
    }
    if(check_finish){
        for (unsigned int i = 0; i < lab[lab.size()].size(); ++i) {
            if(!check && lab[lab.size()][i] == ' '){
                lab[lab.size()][i] = 's';
                check = true;
            }else if(check && lab[lab.size()][i] == ' '){
                lab[lab.size()][i] = 'g';
                check_finish = true;
            }
        }
    }
    if(check_finish){
        for (unsigned int i = 0; i < lab.size(); ++i) {
            if(!check && lab[i][lab.size()] == ' '){
                lab[i][lab.size()] = 's';
                check = true;
            }else if(check && lab[i][lab.size()] == ' '){
                lab[i][lab.size()] = 'g';
                check_finish = true;
            }
        }
    }
    if(check_finish){
        for (unsigned int i = 0; i < lab[0].size(); ++i) {
            if(!check && lab[0][i] == ' '){
                lab[0][i] = 's';
                check = true;
            }else if(check && lab[0][i] == ' '){
                lab[0][i] = 'g';
            }
        }
    }

}

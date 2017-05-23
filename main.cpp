#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <thread>
#include "maze.h"
#include "robot.h"
#include "robot_lefthand.h"
#include "robot_tremaux.h"
#include "robot_gastontarry.h"

void printUsageInfo(){
    std::cout << "Labrob Usage" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "labrob filename_for_maze [optional_parameters]" << std::endl << std::endl;
    std::cout << "Possible Parameters:" << std::endl;
    std::cout << "-h    print this help info" << std::endl;
    std::cout << "-t1   send a Left Hand Robot through the maze" << std::endl;
    std::cout << "-t2   send a Tremaux Robot through the maze" << std::endl;
    std::cout << "-t3   send a Gaston Tarry Robot through the maze" << std::endl;
}

int main(int argc, char *argv[]) {
    std::vector<Robot*> robots;
    int onlyshowusage = 0;
    if(argc <= 1){
        std::cout << "Not all necessary parameters specified!" << std::endl;
        printUsageInfo();
        return -1;
    }

    // Check if file exists
    std::string filename = argv[1];
    if(!std::ifstream(filename)){
        std::cout << "File does not exist or could not be read! Exiting..." << std::endl;
        return -1;
    }

    // Create maze
    Maze* maze = new Maze();
    maze->readFromFile(filename);

    // Parse params
    for(int i = 2; i < argc; i++){
        if(strcmp(argv[i], "-t1") == 0){
            robots.push_back(new LeftHand(maze));
        }else if(strcmp(argv[i], "-t2") == 0) {
            robots.push_back(new Tremaux(maze));
        }else if(strcmp(argv[i], "-t3") == 0) {
            robots.push_back(new GastonTarry(maze));
        }else if(strcmp(argv[i], "-h") == 0) {
            onlyshowusage = 1;
        }
    }

    if(onlyshowusage){
        // Show usage
        printUsageInfo();
    }else{
        // Send robots through maze
    }

    // Clean up
    for(unsigned int i = 0; i < robots.size(); i++){
        delete robots.at(i);
        robots.erase(robots.begin()+i);
    }
    delete maze;
    return 0;
}
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
#include "robot_fill_deadend.h"

void printUsageInfo(){
    std::cout << "Usage: labrob [filename_for_maze] [optional_parameters]" << std::endl << std::endl;
    std::cout << "Possible Parameters:" << std::endl;
    std::cout << "-h    print this help info" << std::endl;
    std::cout << "-p    print maze before robots start search" << std::endl;
    std::cout << "-t1   send a Left Hand Robot through the maze" << std::endl;
    std::cout << "-t2   send a Tremaux Robot through the maze" << std::endl;
    std::cout << "-t3   send a Gaston Tarry Robot through the maze" << std::endl;
    std::cout << "-t4   send a Fill Deadend Robot through the maze" << std::endl;
}

int main(int argc, char *argv[]) {
    std::vector<Robot*> robots;
    std::vector<std::thread> threads;
    bool onlyshowusage = false;
    bool printMaze = false;
    if(argc <= 1){
        std::cout << "Not all necessary parameters specified!" << std::endl;
        std::cout << std::endl;
        printUsageInfo();
        return -1;
    }

    // Check if file exists
    std::string filename = argv[1];
    if(!std::ifstream(filename)){
        std::cout << "Specified file does not exist or could not be read!" << std::endl;
        std::cout << std::endl;
        printUsageInfo();
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
        }else if(strcmp(argv[i], "-t4") == 0){
            robots.push_back(new fill_deadend(maze));
        }else if(strcmp(argv[i], "-h") == 0) {
            onlyshowusage = true;
        }else if(strcmp(argv[i], "-p") == 0) {
            printMaze = true;
        }else{
            std::cout << "Invalid parameters specified!" << std::endl;
            std::cout << std::endl;
            printUsageInfo();
            return -1;
        }
    }

    // If no robot was passed as param, choose t1 as default
    if(robots.size() <= 0){
        robots.push_back(new LeftHand(maze));
    }

    if(onlyshowusage){
        // Show usage
        printUsageInfo();
    }else{
        if(printMaze) {
            maze->printMaze();
            std::cout << std::endl;
        }
        // Send robots through maze
        for(unsigned int i = 0; i < robots.size(); i++){
            std::cout << "Robot " << robots.at(i)->getName() << " started its search!" << std::endl;
            threads.push_back(std::thread(&Robot::startRobot,robots.at(i)));
        }
    }

    // Wait for thread completion
    for(unsigned int i = 0; i < robots.size(); i++){
        threads.at(i).join();
        robots.at(i)->printMaze();
        robots.at(i)->printEndInfo();
    }

    // Clean up
    for(unsigned int i = 0; i < robots.size(); i++){
        delete robots.at(i);
        //robots.erase(robots.begin()+i);
    }
    delete maze;
    return 0;
}
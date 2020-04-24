#include <iostream>
#include "../include/Console/console.hpp"
#include <ros/ros.h>
#include <stdlib.h>
#include "auxiliary/controls.h"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "Console");
    ros::NodeHandle n;
    
    console::consoleNode * ConsoleNode = new console::consoleNode(n);

    ros::AsyncSpinner spinner(1);
    spinner.start();
    ros::waitForShutdown();

    delete ConsoleNode;
    ConsoleNode = nullptr;

    return 0;
}


#ifndef CONSOLE_H 
#define CONSOLE_H

#include <ros/ros.h>
#include <iostream>
#include <thread>
#include "Console/gripper.h"
#include "Console/setpoint.h"
#include <opencv2/opencv.hpp>

namespace console{
    
class consoleNode
{
public:
    consoleNode(ros::NodeHandle &n);
    ~consoleNode(){};

    void InitPublishers(ros::NodeHandle &n);
    void InitPanelThread();


private:
    ros::Publisher GripperPublisher;
    ros::Publisher SetPointPublisher;
    ros::Subscriber ArmControlSubscriber;
    void PanelThread();

    cv::Mat backGround;
    std::string DisplayName;
};

}



#endif

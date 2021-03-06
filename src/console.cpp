#include "../include/Console/console.hpp"



console::consoleNode::consoleNode(ros::NodeHandle &n){
   
    backGround = cv::Mat(30,30,CV_8UC1,cv::Scalar(0));
    
    DisplayName = "Console";

    this->InitPublishers(n);
    
    this->InitPanelThread();
    //this->InitSubcribers(n);

}

void console::consoleNode::InitPublishers(ros::NodeHandle &n){
    GripperPublisher = n.advertise<Console::gripper>("gripper",10);
    
    SetPointPublisher = n.advertise<Console::setpoint>("setpoint",10);
    //SetTest(50);
    //OptiFlowPublisher = n.advertise<auxiliary::opticalflow>("opticalflow",10);
     
    //std::thread pub(std::bind(&auxiliaryNode::Publish, this));

    //pub.detach();    

}

void console::consoleNode::InitPanelThread(){
    std::thread dat(std::bind(&consoleNode::PanelThread,this));
    dat.detach();

}

void console::consoleNode::PanelThread(){
    ros::Rate LoopRate(10);   
    //const std::vector<float> actionPosition1 {0.02828,0.43488,0.0};
    //const std::vector<float> actionAttitude1 {0.0,0.0,0.0};

    const std::vector<float> actionPosition1 {0.0,0.4347,0.0};
    const std::vector<float> actionAttitude1 {0.0,0.0,0.0};
    
    const std::vector<float> actionPosition2 {0.02828,0.43488,0.0};
    const std::vector<float> actionAttitude2 {25.0,0.0,0.0};

    const std::vector<float> actionPosition3 {0.02828,0.43488,0.0};
    const std::vector<float> actionAttitude3 {-25.0,0.0,0.0};

    const std::vector<float> actionPosition4 {0.0019,0.3852,0.0};
    const std::vector<float> actionAttitude4 {0.0,0.0,0.0};

    const std::vector<float> actionPosition5 {0.0019,0.3852,0.0};
    const std::vector<float> actionAttitude5 {25.0,0.0,0.0};

    const std::vector<float> actionPosition6 {0.0019,0.3852,0.0};
    const std::vector<float> actionAttitude6 {-25.0,0.0,0.0};

    const std::vector<float> actionPosition0 {0.0019,0.3852,0.0};
    const std::vector<float> actionAttitude0 {-25.0,0.0,1000.0};

    Console::setpoint sep;
    Console::gripper gr;

    while(ros::ok()){
        imshow(DisplayName, backGround);
        
        char k = (char)cv::waitKey(1);

        switch (k){
        case 'q':
                std::cout<<"Byebye"<<std::endl;
                break;
        case '1':
                sep.position = actionPosition1;
                sep.attitude = actionAttitude1;
                this->SetPointPublisher.publish(sep);
                std::cout<<"Action One"<<std::endl;
                break;
        case '2':
                sep.position = actionPosition2;
                sep.attitude = actionAttitude2;
                this->SetPointPublisher.publish(sep);
                std::cout<<"Action two"<<std::endl;
                break;
        case '3':
                sep.position = actionPosition3;
                sep.attitude = actionAttitude3;
                this->SetPointPublisher.publish(sep);
                std::cout<<"Action three"<<std::endl;
                break;
            
        case '4':
                sep.position = actionPosition4;
                sep.attitude = actionAttitude4;
                this->SetPointPublisher.publish(sep);
                std::cout<<"Action four"<<std::endl;
                break;
        
        case '5':
                sep.position = actionPosition5;
                sep.attitude = actionAttitude5;
                this->SetPointPublisher.publish(sep);
                std::cout<<"Action five"<<std::endl;
                break;
        
        case '6':
                sep.position = actionPosition6;
                sep.attitude = actionAttitude6;
                this->SetPointPublisher.publish(sep);
                std::cout<<"Action six"<<std::endl;
                break;
        
        case '0':
                sep.position = actionPosition0;
                sep.attitude = actionAttitude0;
                this->SetPointPublisher.publish(sep);
                std::cout<<"reset"<<std::endl;
                break;
        
        case 'b':
                gr.GripSta = 0x00;
                this->GripperPublisher.publish(gr);
                std::cout<<"grasp"<<std::endl;
                break;
        case 'n':
                gr.GripSta = 0x01;
                this->GripperPublisher.publish(gr);
                std::cout<<"loop"<<std::endl;
                break;
        case 'm':
                gr.GripSta = 0xff;
                this->GripperPublisher.publish(gr);
                std::cout<<"stop"<<std::endl;
                break;

        case 'g':
                std::cout<<"Grasp"<<std::endl;
                break;
        case 'l':
                std::cout<<"loss"<<std::endl;
                break;
        case 's':
                std::cout<<"stop"<<std::endl;
                break;
        }
        LoopRate.sleep();
    }
}

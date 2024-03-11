#include "ros/ros.h"
#include"std_msgs/String.h"
void writeMsgToLog(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("%s",msg->data.c_str());
}
int main(int argc, char **argv)
{	
	std::string name;
	std::cout<<"Enter username: ";				
	std::getline(std::cin, name);
	ros::init(argc,argv,name);
	ros:: NodeHandle nh;
	ros::Publisher topic_pub=nh.advertise<std_msgs::String>("learn",1000);	
	ros::Rate loop_rate(1);	
	ros:: Subscriber topic_sub =nh.subscribe("learn", 1000,writeMsgToLog);
	ros::AsyncSpinner spinner(1);
	spinner.start();		
	while(ros::ok())
	{			
		std_msgs::String msg;
		std::string message;
		std::getline(std::cin, message);
		msg.data= "Message by "+name+": "+message;
		topic_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}

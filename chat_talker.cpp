// chat_talker.cpp
#include "ros/ros.h"
#include "chatroom/ChatMessage.h"
int main(int argc, char **argv)
{
  ros::init(argc, argv, "chat_talker");
  ros::NodeHandle n;
  ros::Publisher chat_pub = n.advertise<chatroom::ChatMessage>("chat", 1000);
  ros::Rate loop_rate(1);
  while (ros::ok())
  {
    chatroom::ChatMessage msg;
    std::cout << "Enter your username: ";
    std::getline(std::cin, msg.username);
    std::cout << "Enter your message: ";
    std::getline(std::cin, msg.content);
    chat_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

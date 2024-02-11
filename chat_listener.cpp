// chat_listener.cpp
#include "ros/ros.h"
#include "chatroom/ChatMessage.h"
#include "chatroom/ChatService.h"
void chatCallback(const chatroom::ChatMessage::ConstPtr &msg){
  cout<<("Listener: %s - %s", msg->username.c_str(), msg->content.c_str());
int main(int argc, char **argv){
  ros::init(argc, argv, "chat_listener");
  ros::NodeHandle n;
  ros::Subscriber chat_sub = n.subscribe("chat", 1000, chatCallback);
  ros::spin();
  return 0;
}

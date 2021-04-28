#include "listener.hpp"

Listener::Listener(): Node("listener")
{
  msg_sub_ = this->create_subscription<std_msgs::msg::String>(
               "conversation", 10,
               std::bind(&Listener::msg_callback_, this, std::placeholders::_1));
}

void Listener::msg_callback_(const std_msgs::msg::String::SharedPtr msg) const
{
  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Listener>());
  rclcpp::shutdown();
  return 0;
}

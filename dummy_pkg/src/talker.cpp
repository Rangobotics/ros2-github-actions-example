#include "talker.hpp"

Talker::Talker(): Node("talker"), count_(0)
{
  msg_pub_ = this->create_publisher<std_msgs::msg::String>("conversation", 10);
  timer_sub_ = this->create_wall_timer(
                 1000ms, std::bind(&Talker::timer_callback_, this));
}

void Talker::timer_callback_()
{
  auto message = std_msgs::msg::String();
  message.data = "Hello, world! " + std::to_string(count_++);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
  msg_pub_->publish(message);
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Talker>());
  rclcpp::shutdown();
  return 0;
}

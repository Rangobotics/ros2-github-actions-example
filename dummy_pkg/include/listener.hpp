#ifndef LISTENER_HPP
#define LISTENER_HPP

#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


class Listener : public rclcpp::Node
{
  public:
    Listener();

  private:
    void msg_callback_(const std_msgs::msg::String::SharedPtr msg) const;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr msg_sub_;
};

#endif // LISTENER_HPP

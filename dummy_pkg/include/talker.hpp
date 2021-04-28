#ifndef TALKER_HPP
#define TALKER_HPP

#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class Talker: public rclcpp::Node
{
  public:
    Talker();

  private:
    void timer_callback_();
    rclcpp::TimerBase::SharedPtr timer_sub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr msg_pub_;
    size_t count_;
};

#endif // TALKER_HPP

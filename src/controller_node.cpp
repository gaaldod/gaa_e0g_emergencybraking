#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/bool.hpp"

class ControllerNode : public rclcpp::Node
{
public:
  ControllerNode() : Node("controller_node")
  {
    subscription_ = this->create_subscription<std_msgs::msg::Bool>(
      "obstacle", 10, std::bind(&ControllerNode::brake_callback, this, std::placeholders::_1));
  }

private:
  void brake_callback(const std_msgs::msg::Bool::SharedPtr msg) const
  {
    if (msg->data) {
      RCLCPP_WARN(this->get_logger(), "Obstacle detected! Emergency braking activated.");
    } else {
      RCLCPP_INFO(this->get_logger(), "No obstacle detected.");
    }
  }

  rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ControllerNode>());
  rclcpp::shutdown();
  return 0;
}

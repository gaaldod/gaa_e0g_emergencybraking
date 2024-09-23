#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/bool.hpp"

class SensorNode : public rclcpp::Node
{
public:
  SensorNode() : Node("sensor_node")
  {
    publisher_ = this->create_publisher<std_msgs::msg::Bool>("obstacle", 10);
    timer_ = this->create_wall_timer(
      std::chrono::seconds(1),
      std::bind(&SensorNode::publish_obstacle, this));
  }

private:
  void publish_obstacle()
  {
    auto message = std_msgs::msg::Bool();
    message.data = std::rand() % 2;   // Simulate obstacle detection; Randomly set to true or false
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data ? "true" : "false");
    publisher_->publish(message);
  }

  rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SensorNode>());
  rclcpp::shutdown();
  return 0;
}

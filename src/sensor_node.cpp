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
    static float distance = 30.0;
    auto message = std_msgs::msg::Bool();
    float decrement = static_cast<float>(std::rand() % 3) + 0.5; // Random decrement between 0.5 and 2.5
    if (distance > decrement) {
      distance -= decrement;
    } else {
      distance = 0;
    }
    message.data = (distance > 10); //if distance is greater than 10, then there is no obstacle
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

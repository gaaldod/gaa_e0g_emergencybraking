#include "sensor_msgs/msg/temperature.hpp"
#include "sensor_msgs/msg/relative_humidity.hpp"
#include <rclcpp/rclcpp.hpp>

using std::placeholders::_1;

class SensorNode : public rclcpp::Node
{
public:
  SensorNode() : Node("sensor_node")
  {
    distance_pub = this -> create_publisher<sensor_msgs::msg::Distance>("distance", 1);
    speed_pub = this -> create_publisher<sensor_msgs::msg::Speed>("speed, 1");
  }
  
  rclcpp::Publisher<sensor_msgs::msg::Distance>::SharedPtr distance_pub;
  rclcpp::Publisher<sensor_msgs::msg::Speed>::SharedPtr speed_pub;


}
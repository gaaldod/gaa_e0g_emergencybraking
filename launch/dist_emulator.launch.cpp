#include <rclcpp/rclcpp.hpp>
#include <stdexcept>

//generate launch description
int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node1 = std::make_shared<rclcpp::Node>("sensor_node");
    auto node2 = std::make_shared<rclcpp::Node>("sensor_monitor");

    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node1);
    executor.add_node(node2);

    executor.spin();

    rclcpp::shutdown();
    return 0;
}

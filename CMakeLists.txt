cmake_minimum_required(VERSION 3.5)
project(emergency_braking_system)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
unset(CATKIN_INSTALL_INTO_PREFIX_ROOT CACHE)

add_executable(sensor_node src/sensor_node.cpp)
ament_target_dependencies(sensor_node rclcpp std_msgs)

add_executable(controller_node src/controller_node.cpp)
ament_target_dependencies(controller_node rclcpp std_msgs)

install(TARGETS
  sensor_node
  controller_node
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch)

ament_package()

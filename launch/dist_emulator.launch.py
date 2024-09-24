from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gaa_e0g_emergencybraking',
            executable='sensor_node',
            output='screen'
        ),
        Node(
            package='gaa_e0g_emergencybraking',
            executable='controller_node',
            output='screen'
        ),
    ])
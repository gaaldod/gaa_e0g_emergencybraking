from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='emergency_braking_system',
            executable='sensor_node',
            output='screen'
        ),
        Node(
            package='emergency_braking_system',
            executable='controller_node',
            output='screen'
        ),
    ])
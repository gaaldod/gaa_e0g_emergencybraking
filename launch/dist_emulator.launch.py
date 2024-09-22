from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='dist_sens',
            executable='sensor_node',
            output='screen'
        ),
        Node(
            package='dist_sens',
            executable='sensor_monitor',
            output='screen'
        ),
    ])
# #!/usr/bin/env python3

import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.actions import SetEnvironmentVariable
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration

# from launch.substitutions import ThisLaunchFileDir
from launch_ros.actions import Node
from nav2_common.launch import RewrittenYaml


def generate_launch_description():

    talker = Node(
        package="dummy_pkg", executable="talker", name="talker", output="screen"
    )

    listener = Node(
        package="dummy_pkg", executable="listener", name="listener", output="screen"
    )

    ld = LaunchDescription()

    ld.add_action(talker)
    ld.add_action(listener)

    return ld

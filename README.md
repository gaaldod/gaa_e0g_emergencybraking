# `ros2_cpp_template` package
ROS 2 C++ package.
## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
git clone https://github.com/sze-info/ros2_cpp_template
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
colcon build --packages-select ros2_cpp_template
```

Don't forget to `source` before ROS commands.

``` r
source ~/ros2_ws/install/local_setup.bash
```

``` r
ros2 launch ros2_cpp_template launch_example1.launch.py
```

# Delete this part if you are using it as a template

ROS 2 pacage template, to get started, use template by clicking on the Green button labeled [`Use this template`](https://github.com/sze-info/ros2_cpp_template/generate) / [`Create new repository`](https://github.com/sze-info/ros2_cpp_template/generate). 

![](img/use_this_template01.png)


Let's assume 
- your Github username is `mycoolusername`
- your ROS 2 repo shold be `cool_ros2_package`

Replace everything in the cloned repo:

- `ros2_cpp_template` >> `cool_ros2_package` (the folder was already renamed after `Use this template`)
- `sze-info` >> `mycoolusername`
- find all `todo` strings and fill the blanks

The easiest way is VS code:

![](img/replace01.png)

Now colocn build your ROS 2 package and you can start wokring.
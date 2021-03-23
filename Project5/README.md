# Project5: Home Service Robot

### Goal
Program a robot that can autonomously map an environment and navigate to pick up and drop virtual objects.

### Directory Structure

```
catkin_ws/src
    ├── slam_gmapping                  # gmapping_demo.launch file                   
    │   ├── gmapping
    │   ├── ...
    ├── turtlebot                      # keyboard_teleop.launch file
    │   ├── turtlebot_teleop
    │   ├── ...
    ├── turtlebot_interactions         # view_navigation.launch file      
    │   ├── turtlebot_rviz_launchers
    │   ├── ...
    ├── turtlebot_simulator            # turtlebot_world.launch file and kelly.world file
    │   ├── turtlebot_gazebo
    │   │   ├── worlds
    │   │   │   ├── kelly.world
    │   │   ├── ...
    │   ├── ...
    ├── scripts                   # shell scripts files
    │   ├── ...
    ├──rvizConfig                      # rviz configuration files
    │   ├── ...
    ├──pick_objects                    # pick_objects C++ node
    │   ├── src/pick_objects.cpp
    │   ├── ...
    ├──add_markers                     # add_marker C++ node
    │   ├── src/add_markers.cpp
    │   ├── ...
    └──
```

### Steps to launch the simulation

#### Step 1. Update the system
`sudo apt-get update`

#### Step 2. Install the ROS navigation stack
`sudo apt-get install ros-kinetic-navigation`

#### Step 3. Create catkin workspace
```sh
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ catkin_init_workspace
$ cd ~/catkin_ws
$ catkin_make
```
#### Step 4. Clone the following repositories to catkin_ws/src
```sh
$ cd ~/catkin_ws/src
$ git clone https://github.com/ros-perception/slam_gmapping.git
$ git clone https://github.com/turtlebot/turtlebot.git
$ git clone https://github.com/turtlebot/turtlebot_interactions.git
$ git clone https://github.com/turtlebot/turtlebot_simulator.git
```
Install package dependencies with `rosdep install [package-name]`

#### Step 5. Source and build the project
```sh
$ cd ~/catkin_ws
$ source devel/setup.bash
$ catkin_make
```
Run `./home_service.sh` in `scripts` directory to deploy the home service robot.

### Output
Gazebo should launch the environment that has turtlebot inside the building. Then RViz should map the environment around the turtlebot. The marker should be located near the entrance of the building. The robot should start moving towards the marker and once the robot reaches to the marker, the marker should be "picked up" by the robot. The robot should then move back to the original spot and "drop off" the marker.

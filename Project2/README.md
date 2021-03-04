# Project2: Go Chase It!

### Goal
Design and build a mobile robot, and house it in my world I previously designed. Then, program my robot with C++ nodes in ROS to chase white colored ball.

### Directory Structure
```
  .Project2                          # Go Chase It Project
  ├── my_robot                       # my_robot package                   
  │   ├── launch                     # launch folder for launch files   
  │   │   ├── robot_description.launch
  │   │   ├── world.launch
  │   ├── meshes                     # meshes folder for sensors
  │   │   ├── hokuyo.dae
  │   ├── urdf                       # urdf folder for xarco files
  │   │   ├── my_robot.gazebo
  │   │   ├── my_robot.xacro
  │   ├── world                      # world folder for world files
  │   │   ├── myworld.world
  │   ├── CMakeLists.txt             # compiler instructions
  │   ├── package.xml                # package info
  ├── ball_chaser                    # ball_chaser package                   
  │   ├── launch                     # launch folder for launch files   
  │   │   ├── ball_chaser.launch
  │   ├── src                        # source folder for C++ scripts
  │   │   ├── drive_bot.cpp
  │   │   ├── process_images.cpp
  │   ├── srv                        # service folder for ROS services
  │   │   ├── DriveToTarget.srv
  │   ├── CMakeLists.txt             # compiler instructions
  │   ├── package.xml                # package info                  
  └──                      
```

### Steps to launch the simulation

#### Step 1 Update and upgrade the Workspace image
```sh
$ sudo apt-get update
$ sudo apt-get upgrade -y
```

#### Step 2 Clone the lab folder in /home/workspace/
```sh
$ cd /home/workspace/
$ git clone https://github.com/sylee538/Udacity-Robotics-Software-Engineering/Project2
```

#### Step 3 Compile the code
```sh
$ cd /home/workspace/Project2/catkin_ws
$ mkdir build
$ cd build/
$ cmake ../
$ make
```

#### Step 4 Launch myworld on Gazebo
```sh
$ cd /home/workspace/Project2/catkin_ws
$ source devel/setup.#!/usr/bin/env bash
$ roslaunch my_robot world.launch
```

#### Step 5 Launch ball_chaser on separate terminal
```sh
$ cd /home/workspace/Project2/catkin_ws/
$ source devel/setup.bash
$ roslaunch ball_chaser ball_chaser.launch
```

### Output

Myrobot inside myworld in Gazebo as well as RViz. The white ball should be located outside the building. Now place the white ball at different positions in front of the robot and see if the robot is capable of chasing the ball!
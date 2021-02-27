# Project1: Build My World

### Goal
Design a Gazebo World environment including mulitple models and use it as a base for the rest of my projects.

### Directory Structure
```
    .                          
    ├── CMakeLists.txt                 # Link libraries               
    ├── model                          # Model file of my Gazebo world and my robot
    │   ├── Building
    │   │   ├── model.config
    │   │   ├── model.sdf
    |   ├── VacuumRobot
    │   │   ├── model.config
    │   │   ├── model.sdf
    ├── script                         # Gazebo World plugin C++ script      
    │   ├── hello.cpp
    └── world                          # Gazebo main World
        └── myworld                     
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
$ git clone https://github.com/sylee538/Udacity-Robotics-Software-Engineering/Project1
```

#### Step 3 Compile the code
```sh
$ cd /home/workspace/Project1/
$ mkdir build
$ cd build/
$ cmake ../
$ make
```

#### Step 4 Add the library path to the Gazebo plugin path  
```sh
$ export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/workspace/Project1/build
```

#### Step 5 Run the Gazebo World file  
```sh
$ cd /home/workspace/Project1/world/
$ gazebo myworld
```

### Output
The 'Welcome to Kelly's World' message and two VacuumRobots inside a Gazebo World should both launch.

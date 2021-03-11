# Project4: Map My World

### Goal
Create a 2D occupancy grid and 3D octomap from a simulated environment using my robot with the RTAB-MAP package.

### Steps to launch the simulation

#### Step 1 Update and upgrade the Workspace image
```sh
$ sudo apt-get update
$ sudo apt-get upgrade -y
```

#### Step 2 Clone the lab folder in /home/workspace/
```sh
$ cd /home/workspace/
$ git clone https://github.com/sylee538/Udacity-Robotics-Software-Engineering.git
```

#### Step 3 Launch the simulation
```sh
$ cd /home/workspace/Project4/catkin_ws
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```

#### Step 4 Launch teleop node
```sh
$ cd /home/workspace/Project4/catkin_ws
$ source devel/setup.bash
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

#### Step 5 Launch mapping.launch
```sh
$ cd /home/workspace/Project4/catkin_ws
$ source devel/setup.bash
$ roslaunch my_robot mapping.launch
```

#### Step 4 Open mapping database
```sh
$ cd /root/.ros/
$ rtabmap-databaseViewer ~/.ros/rtabmap.db
```
Say yes to using the database parameters
View -> Constraint View
View -> Graph View

### Output
Navigate the robot in the simulation to create map for the environment. Map db file will be located in the /root/.ros/ folder. Check the example output inside db folder. 

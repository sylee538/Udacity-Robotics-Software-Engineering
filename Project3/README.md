# Project3: Where Am I?

### Goal
Use the Adaptive Monte Carlo Localization algorithm in ROS to localize my robot.

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
$ cd /home/workspace/Project3/catkin_ws
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```

#### Step 4 Launch amcl launch file
```sh
$ cd /home/workspace/Project3/catkin_ws
$ source devel/setup.bash
$ roslaunch my_robot amcl.launch
```
#### Step 5 Test it!
##### Option 1: Send 2D Navigation Goal from RViz
Click the 2D Nav Goal button in the toolbar, then click and drag on the map to send the goal to the robot. It will start moving and localize itself in the process.

##### Option 2: Use teleop node
```sh
$ cd /home/workspace/Project3/catkin_ws/src
$ git clone https://github.com/ros-teleop/teleop_twist_keyboard
$ cd /home/workspace/Project3/catkin_ws
$ catkin_make
$ source devel/setup.bash
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
Now, you can control my robot by keyboard commands.

### Output
![image](./image/result.png)

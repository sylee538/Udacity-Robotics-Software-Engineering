#!/bin/sh
xterm  -e  " source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/turtlebot_simulator/turtlebot_gazebo/worlds/kelly.world" &
sleep 5
xterm -e "source /home/workspace/catkin_ws/devel/setup.bash ; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/workspace/catkin_ws/src/map/kelly_map.yaml" &
sleep 10
xterm -e "source /home/workspace/catkin_ws/devel/setup.bash ; roslaunch turtlebot_rviz_launchers view_navigation.launch rviz_config_file_path:=/home/workspace/catkin_ws/src/rvizConfig/marker_added.rviz" &
sleep 20
xterm -e "source /home/workspace/catkin_ws/devel/setup.bash ; rosrun add_markers add_markers" &
sleep 10
xterm -e "source /home/workspace/catkin_ws/devel/setup.bash ; rosrun pick_objects pick_objects"
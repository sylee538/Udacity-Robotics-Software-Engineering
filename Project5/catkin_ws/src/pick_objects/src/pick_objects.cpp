#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the pick_objects node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach near the front door
  goal.target_pose.pose.position.x = -6.0;
  goal.target_pose.pose.position.y = 2.0;
  goal.target_pose.pose.orientation.w = 1.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending the robot to reach near the front door");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Reached to the door!");
  else
    ROS_INFO("The robot failed to move to the door for some reason");
  
  // Wait 5 sec after reaching towards the door
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting 5 seconds until the next move");
  }
  
  move_base_msgs::MoveBaseGoal sink;

  // set up the frame parameters
  sink.target_pose.header.frame_id = "map";
  sink.target_pose.header.stamp = ros::Time::now();  

  // Define a position and orientation for the robot to move back to the original spot
  sink.target_pose.pose.position.x = 0.0;
  sink.target_pose.pose.position.y = 0.0;
  sink.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending the robot back to the original spot");
  ac.sendGoal(sink);
  
    // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Came back to the original spot");
  else
    ROS_INFO("The robot failed to move back to the original spot for some reason");


  return 0;
}
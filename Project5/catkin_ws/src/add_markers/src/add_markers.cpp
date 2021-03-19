#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "nav_msgs/Odometry.h"
#include <math.h>

//Pickup/Dropoff position
float pickUp[3] = {-6.0, 2.0, 1.0};
float dropOff[3] = {0.0, 0.0, 1.0};

// Flags
bool atDropOff = false;
bool atPickUp = false;
bool pickedUp = false;
bool droppedOff = false;

//callback function to check if the turtlebot is at the drop off/pick up location
void chatterCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  //if the robot is at the pickup location, set atPickUp to true
  if (abs(pickUp[0] - msg->pose.pose.position.x) < 0.3 && abs(pickUp[1] - msg->pose.pose.position.y) < 0.3) {
    atPickUp = true;
  } else { atPickUp = false; }
  
  //if the robot is at the dropoff location, set atDropOff to true
  if (abs(dropOff[0] - msg->pose.pose.position.x) < 0.3 && abs(dropOff[1] - msg->pose.pose.position.y) < 0.3) {
    atDropOff = true;
  } else { atDropOff = false; }
  
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber odom_sub = n.subscribe("odom", 1000, chatterCallback);


  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  while (ros::ok())
  {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = pickUp[0];
    marker.pose.position.y = pickUp[1];
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 0.5x0.5x0.5 here means 0.5m on a side
    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
     }
    
     //Publish marker at pick up zone
     marker_pub.publish(marker);
     ROS_INFO("Marker at pick up zone");
     
     // Wait for the robot to get to the pick up zone
     while (!atPickUp) {
       ros::spinOnce();
     }
   
     //Robot picks up the marker at the pick up zone
     if(atPickUp && !pickedUp) {
       marker.action = visualization_msgs::Marker::DELETE;
       marker_pub.publish(marker);
       ROS_INFO("Robot picked up the marker");
       pickedUp = true;
     }  
   
     // Wait for the robot to get to the drop off zone
     while (!atDropOff) {
       ros::spinOnce();
     }
   
     // Robot drops off the marker at the drop off zone
     if(atDropOff && !droppedOff) {  
       marker.pose.position.x = dropOff[0];
       marker.pose.position.y = dropOff[1];
       marker.action = visualization_msgs::Marker::ADD;
       marker_pub.publish(marker);
       ROS_INFO("Robot dropped off the marker");
       droppedOff = true;
       ros::Duration(5.0).sleep();
     }  
    return 0;
  }
    
}

#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
  ROS_INFO_STREAM("Moving robot to designated place");
  ball_chaser::DriveToTarget srv;

  srv.request.linear_x = lin_x;
  srv.request.angular_z = ang_z;
  ROS_INFO("Setting - linear_x: %1.2f, angular_z: %1.2f", (float)srv.request.linear_x, (float)srv.request.angular_z);

  if(!client.call(srv))
    ROS_ERROR("Failed to call service command_robot");
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;

//     bool turn_left = false;
//     bool turn_right = false;
//     bool move_forward = false;

    int left_edge = img.step/3;
    int mid_edge = 2 * img.step/3;
    int right_edge = img.step;

    // Loop through each pixel in the image and check if there's a bright white one
    for(int i = 0; i < img.height * img.step; i+=3) {
      
      if (img.data[i] == white_pixel && img.data[i+1] == white_pixel && img.data[i+2] == white_pixel){
    // Then, identify if this pixel falls in the left, mid, or right side of the image
        int ball = i % img.step;
        //std::cout << "FOUND IT!" << std::endl; //If the white ball is found

        if (ball >= 0 && ball <= left_edge){
//           turn_left = true;
//           turn_right = false;
//           move_forward = false;
          ROS_INFO("Turning Left");
          drive_robot(0.1, -0.1);
          break;
        }
        else if (ball > left_edge && ball <= mid_edge){
//           move_forward = true;
//           turn_right = false;
//           turn_left = false;
          ROS_INFO("Driving Forward");
          drive_robot(0.1, 0.0);
          break;
        }
        else if (ball > mid_edge && ball <= right_edge){
//           turn_right = true;
//           turn_left = false;
//           move_forward = false;
          ROS_INFO("Turning Right");
          drive_robot(0.1,0.1);
          break;
        }
      }
      else {
        ROS_INFO("Driving Stopped");
        drive_robot(0.0, 0.0);
      }
    }
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
//     if(turn_right){
//       ROS_INFO("Turning Right");
//       drive_robot(0.1,0.1);
//     }
//     else if(turn_left){
//       ROS_INFO("Turning Left");
//       drive_robot(0.1, -0.1);
//     }
//     else if(move_forward){
//       ROS_INFO("Driving Forward");
//       drive_robot(0.1, 0.0);
//     }
//     else if(!move_forward && !turn_left && !turn_right){
//       ROS_INFO("Driving Stopped");
//       drive_robot(0.0, 0.0);
//     }
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}

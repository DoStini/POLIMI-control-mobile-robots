#include <ros/ros.h>
#include "std_msgs/String.h"
#include "std_msgs/UInt32.h"
#include <stdint.h>

uint32_t remaining_nodes = 3;


/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "system_clock");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  ros::Publisher publisher = n.advertise<std_msgs::UInt32>("sum", 1000);

  while (ros::ok() && remaining_nodes > 0)
  {
    ros::spinOnce();

    loop_rate.sleep();
    ++timer;
  }


  return 0;
}


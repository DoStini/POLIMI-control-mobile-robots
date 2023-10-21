#include "ros/ros.h"
#include "std_msgs/UInt32.h"

// TODO: REPLACE WITH C1
uint32_t counter_value = 0;
ros::Publisher publisher;

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const std_msgs::UInt32::ConstPtr& msg) {
    ROS_INFO("CLOCK RECEIVED: [%d]", msg->data);
    uint32_t C2 = 3;

    if ((counter_value++) != C2) {
        return;
    }

    std_msgs::UInt32 value_msg;
    value_msg.data = counter_value;

    publisher.publish(value_msg);
    ros::shutdown();
}

int main(int argc, char** argv) {
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
    ros::init(argc, argv, "counter");

    /**
     * NodeHandle is the main access point to communications with the ROS system.
     * The first NodeHandle constructed will fully initialize this node, and the last
     * NodeHandle destructed will close down the node.
     */
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("clock", 1000, chatterCallback);
    publisher = n.advertise<std_msgs::UInt32>("value", 1000);


    /**
     * ros::spin() will enter a loop, pumping callbacks.  With this version, all
     * callbacks will be called from within this thread (the main one).  ros::spin()
     * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
     */
    ros::spin();

    return 0;
}

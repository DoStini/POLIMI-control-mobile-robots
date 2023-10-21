#include <ros/ros.h>
#include "std_msgs/String.h"
#include "std_msgs/UInt32.h"
#include <stdint.h>

#include <sstream>

int main(int argc, char** argv) {
    ros::init(argc, argv, "system_clock");

    ros::NodeHandle n;

    ros::Publisher publisher = n.advertise<std_msgs::UInt32>("clock", 1000);

    ros::Rate loop_rate(0.2); // TODO CHANGE TO CORRECT VALUE

    uint32_t timer = 0;
    while (ros::ok()) {
        std_msgs::UInt32 msg;
        msg.data = timer;

        // ROS_INFO("CLOCK VALUE SENT: %d", msg.data);

        publisher.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        ++timer;
    }

    return 0;
}

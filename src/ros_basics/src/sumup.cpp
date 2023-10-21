#include <ros/ros.h>
#include "std_msgs/String.h"
#include "std_msgs/UInt32.h"
#include <stdint.h>
#include <numeric>

uint32_t remaining_nodes = 3; // TODO REPLACE WITH N
std::vector<uint32_t> values;
ros::Publisher publisher;


void callback(const std_msgs::UInt32::ConstPtr& msg) {
    values.push_back(msg->data);
    // ROS_INFO("Value received: [%d]", msg->data);

    if ((--remaining_nodes) != 0) {
        return;
    }

    uint32_t total = std::accumulate(values.begin(), values.end(), 0) * 2; // TODO: REPLACE WITH alpha

    std_msgs::UInt32 value_msg;
    value_msg.data = total;

    publisher.publish(value_msg);

    ROS_INFO("The result is %d", total);

    ros::shutdown();
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "system_clock");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("value", 1000, callback);

    publisher = n.advertise<std_msgs::UInt32>("sum", 1000);

    ros::spin();

    return 0;
}


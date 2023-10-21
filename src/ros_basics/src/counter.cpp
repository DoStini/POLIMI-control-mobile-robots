#include "ros/ros.h"
#include "std_msgs/UInt32.h"

// TODO: REPLACE WITH C1
uint32_t counter_value = 0;
ros::Publisher publisher;

void callback(const std_msgs::UInt32::ConstPtr& msg) {
    // ROS_INFO("CLOCK RECEIVED: [%d]", msg->data);
    uint32_t C2 = 3;

    if ((++counter_value) != C2) {
        return;
    }

    std_msgs::UInt32 value_msg;
    value_msg.data = counter_value;

    publisher.publish(value_msg);
    ros::shutdown();
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "counter");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("clock", 1000, callback);
    publisher = n.advertise<std_msgs::UInt32>("value", 1000);

    ros::spin();

    return 0;
}

#include <cmath>

#include "ros/ros.h"
#include "std_msgs/Float64.h"

int main(int argc, char** argv) {
  ros::init(argc, argv, "sin_publisher");
  ros::NodeHandle n;
  ros::Publisher sin_pub = n.advertise<std_msgs::Float64>("/sin_value", 1000);
  ros::Rate loop_rate(10);
  double x = 0.0;
  while (ros::ok()) {
    std_msgs::Float64 msg;
    msg.data = std::sin(x);
    sin_pub.publish(msg);
    x += 1.0;
    loop_rate.sleep();
  }
}

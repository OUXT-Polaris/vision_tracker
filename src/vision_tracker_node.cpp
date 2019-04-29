// headers in ROS
#include <ros/ros.h>

// headers in this package
#include <vision_tracker/vision_tracker.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "rostate_machine_node");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");
    vision_tracker::VisionTracker tracker(nh,pnh);
    ros::spin();
    return 0;
}
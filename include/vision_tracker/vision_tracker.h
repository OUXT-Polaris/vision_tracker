#ifndef VISION_TRACKER_H_INCLUDED
#define VISION_TRACKER_H_INCLUDED

// Headers in OpenCV
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>

// Headers in ROS
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <image_transport/subscriber_filter.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

// headers in STL
#include <memory>

namespace vision_tracker
{
    class VisionTracker
    {
    public:
        VisionTracker(ros::NodeHandle nh,ros::NodeHandle pnh);
        ~VisionTracker();
    private:
        std::shared_ptr<image_transport::SubscriberFilter> image_subscriber_ptr_;
        ros::NodeHandle nh_;
        ros::NodeHandle pnh_;
        image_transport::ImageTransport it_;
    };
}
#endif  //VISION_TRACKER_H_INCLUDED
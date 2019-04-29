#ifndef VISION_TRACKER_VISION_TRACKER_H_INCLUDED
#define VISION_TRACKER_VISION_TRACKER_H_INCLUDED

// Headers in OpenCV
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/tracking/tldDataset.hpp>
#include <opencv2/tracking.hpp>

// Headers in ROS
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <image_transport/subscriber_filter.h>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <sensor_msgs/Image.h>
#include <vision_msgs/Detection2DArray.h>

// headers in STL
#include <memory>

namespace vision_tracker
{
    typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Image,vision_msgs::Detection2DArray> SyncPolicy;

    class VisionTracker
    {
    public:
        VisionTracker(ros::NodeHandle nh,ros::NodeHandle pnh);
        ~VisionTracker();
    private:
        void detectionCallback(const sensor_msgs::ImageConstPtr& image_ptr,const vision_msgs::Detection2DArray::ConstPtr& detection_ptr);
        std::shared_ptr<image_transport::SubscriberFilter> image_subscriber_ptr_;
        std::shared_ptr<message_filters::Subscriber<vision_msgs::Detection2DArray> > detection_sub_ptr__;
        std::shared_ptr<message_filters::Synchronizer<SyncPolicy> > sync_ptr_;
        ros::NodeHandle nh_;
        ros::NodeHandle pnh_;
        image_transport::ImageTransport it_;
        cv::Ptr<cv::TrackerKCF> kcf_tracker_ptr_;
    };
}
#endif  //VISION_TRACKER_VISION_TRACKER_H_INCLUDED
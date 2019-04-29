// headers in this package
#include <vision_tracker/vision_tracker.h>

namespace vision_tracker
{
    VisionTracker::VisionTracker(ros::NodeHandle nh,ros::NodeHandle pnh):
        nh_(nh),pnh_(pnh),it_(nh)
    {
        image_subscriber_ptr_ = std::make_shared<image_transport::SubscriberFilter>(it_,"image_raw", 1);
        detection_sub_ptr__ = std::make_shared<message_filters::Subscriber<vision_msgs::Detection2DArray> >(nh_,"detection",1);
        sync_ptr_ = std::make_shared<message_filters::Synchronizer<SyncPolicy> >(SyncPolicy(10), *image_subscriber_ptr_, *detection_sub_ptr__);
        sync_ptr_->registerCallback(boost::bind(&VisionTracker::detectionCallback,this,_1, _2));
    }

    VisionTracker::~VisionTracker()
    {

    }

    void VisionTracker::detectionCallback(const sensor_msgs::ImageConstPtr& image_ptr,const vision_msgs::Detection2DArray::ConstPtr& detection_ptr)
    {
        return;
    }
}
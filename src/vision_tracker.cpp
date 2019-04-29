// headers in this package
#include <vision_tracker/vision_tracker.h>

namespace vision_tracker
{
    VisionTracker::VisionTracker(ros::NodeHandle nh,ros::NodeHandle pnh):
        nh_(nh),pnh_(pnh),it_(nh)
    {
        image_subscriber_ptr_ = std::make_shared<image_transport::SubscriberFilter>(it_,"image_raw", 1);
    }

    VisionTracker::~VisionTracker()
    {

    }
}
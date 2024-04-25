
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/hdl_grabber.h>
#include <pcl/visualization/point_cloud_color_handlers.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/console/parse.h>

using namespace std::chrono_literals;
using namespace pcl::console;
using namespace pcl::visualization;

class SimpleHDLViewer
{
    typedef pcl::PointCloud<pcl::PointXYZI> Cloud;
    typedef Cloud::ConstPtr CloudConstPtr;

public:
    SimpleHDLViewer(pcl::Grabber &grabber, PointCloudColorHandler<pcl::PointXYZI> &handler);

    void cloud_callback(const CloudConstPtr &cloud);

    void run();

private:
    PCLVisualizer::Ptr cloud_viewer_;

    pcl::Grabber &grabber_;
    std::mutex cloud_mutex_;

    CloudConstPtr cloud_;
    PointCloudColorHandler<pcl::PointXYZI> &handler_;
};

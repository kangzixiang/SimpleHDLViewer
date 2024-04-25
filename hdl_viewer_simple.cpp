
#include "SimpleHDLViewer.h"
#include <pcl/io/vlp_grabber.h>

int main(int argc, char **argv)
{
  std::string hdlCalibration, pcapFile;

  parse_argument(argc, argv, "-calibrationFile", hdlCalibration);
  parse_argument(argc, argv, "-pcapFile", pcapFile);

  pcapFile = "HDL32-V2_Tunnel.pcap";
  pcl::HDLGrabber grabber(hdlCalibration, pcapFile);
  // pcl::VLPGrabber g(pcapFile);
  PointCloudColorHandlerGenericField<pcl::PointXYZI> color_handler("intensity");

  SimpleHDLViewer v(grabber, color_handler);
  v.run();
  return 0;
}

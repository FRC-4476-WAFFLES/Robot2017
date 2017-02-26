#pragma once

#include <opencv2/opencv.hpp>
#include "run_result.hpp"
#include <cscore.h>

class Vision {
public:
  // devid is the id of the camera (for example /dev/video0 = 0)
  Vision(int devid);

  // Does all of the vision processing and returns a RunResult
  RunResult process_frame();
private:
  cs::UsbCamera camera;
  cs::CvSink camera_sink;
  cs::CvSource server_source;
  cs::MjpegServer server;
  cv::Mat img, hsv, thresh;
  std::vector<std::vector<cv::Point>> contours;

  // Produces a RunResult, assumes that image processing has already been done
  RunResult find_data();

  void draw_largest();
};

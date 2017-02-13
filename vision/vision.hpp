#pragma once

#include <opencv2/opencv.hpp>
#include "run_result.hpp"

class Vision {
public:
  // devid is the id of the camera (for example /dev/video0 = 0)
  Vision(int devid);

  // Does all of the vision processing and returns a RunResult
  RunResult process_frame();
private:
  // Opencv images
  cv::Mat img, hsv, thresh;
  // The camera
  cv::VideoCapture cap;

  // The detected regions
  std::vector<std::vector<cv::Point>> contours;

  // The device id of the camera
  int devid;

  // Produces a RunResult, assumes that image processing has already been done
  RunResult find_data();

  void draw_largest();
};

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include "run_result.hpp"

using namespace cv;

/// Cam horizontal FOV = 53.13degree
/// 12" = 12"
/// 24" = 24"
/// 33" = 32"

/// v4l2-ctl -d /dev/video1 -c exposure_auto=1 -c exposure_absolute=5

Mat img, hsv, thresh;
VideoCapture cap;
std::vector<std::vector<Point>> contours;
timespec start, end;

void draw_largest();
//2 4 4 1'3"

int setup() {
  cap.open(0);
  cap.set(CAP_PROP_FRAME_WIDTH, 640);
  cap.set(CAP_PROP_FRAME_HEIGHT, 360);
  cap.set(CAP_PROP_EXPOSURE, -100);
  cap.set(CAP_PROP_AUTO_EXPOSURE, 0);
  cap.read(img); // Discard first frame
}



RunResult process_frame() {
  cap.read(img);
  cvtColor(img, hsv, CV_BGR2HSV);
  inRange(hsv, Scalar(55,143,84), Scalar(95,255,254), thresh);
  findContours(thresh, contours, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
  return
  // draw_largest();
  //printf("Done!%d\n", contours.size());
  // imwrite("/tmp/out.png", img);
  return find_data();
}

RunResult find_data() {
  double unadjusted_distance = 6008*pow(max(bound.size.width, bound.size.height), -0.938);
  double real_distance = unadjusted_distance *
    (1+0.000003*pow(bound.center.x - 640.0/2.0, 2.0)
      +0.000002*pow(bound.center.y - 360.0/2.0, 2.0));
  double turret_angle = (bound.center.x - 640.0/2.0)*(28.0/320.0);
  return RunResult {
    true,
    turret_angle,
    real_distance,
    0.0, // TODO: time the vision stuff
  }
}

void draw_largest() {
  double largest_area = 0.0;
  int largest_contour_index = -1;
  for(uint32_t i = 0; i<contours.size(); i++) // iterate through each contour.
  {
    double a=contourArea(contours[i],false);  //  Find the area of contour
    if(a>largest_area){
      largest_area=a;
      largest_contour_index=i;                //Store the index of largest contour
    }
  }
  drawContours(img, contours, -1, Scalar(255, 0, 0), 1);
  if(largest_contour_index != -1) {
    auto bound = minAreaRect(contours[largest_contour_index]);
    Point2f rect_points[4]; bound.points( rect_points );
    for(int j = 0; j < 4; j++)
      line( img,rect_points[j], rect_points[(j+1)%4], Scalar(0,0,255),1,8);
  }
}

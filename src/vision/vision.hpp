#pragma once

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <shared_mutex>
#include <thread>
#include "run_result.hpp"

class Vision {
public:
  // devid is the id of the camera (for example /dev/video0 = 0)
  Vision(int devid);

  // Runs the main loop on a seperate thread. Will use minimal cpu while
  // get and get_blocking aren't being called.
  void main_loop();

  // Returns the most recent RunResult
  RunResult get();

  // Wait for the next RunResult
  RunResult get_blocking();
private:
  std::thread thread;

  cv::Mat img, hsv, thresh;
  cv::VideoCapture cap;
  std::vector<std::vector<cv::Point>> contours;
  timespec start, end;

  // The device id of the camera
  int devid;

  // Used for sending the results back to the caller.
  std::condition_variable wait_for_next;
  std::mutex last_result_mutex;
  timespec last_result_capture;
  RunResult last_result;

  // Used for waiting if our results are not being used.
  std::condition_variable wait_for_consumers;
  std::mutex is_being_observed_mutex;
  int32_t is_being_observed = INT_MIN + 1;

  // Does all of the vision processing and returns a RunResult
  RunResult process_frame();

  // Produces a RunResult, assumes that image processing has already been done
  RunResult find_data();
  void draw_largest();

  // Tells the main loop that its data is being used and it should continue.
  void am_listening();
};

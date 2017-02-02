#pragma once
#include "vision/run_result.hpp"
#include <WPILib.h>
class CameraClient{
public:
	 CameraClient();
	 void RunRecieve();
	 std::unique_ptr<Notifier> control_loop;
	 int hsock;
	 RunResult converted;
};

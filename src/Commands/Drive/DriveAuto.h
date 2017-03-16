#pragma once

#include <Timer.h>
#include "CommandBase.h"

class DriveAuto: public CommandBase {
private:
	double distance;
	double angle;
	double speed;
	Timer done;
public:
	DriveAuto(double distance, double angle);
	DriveAuto(double distance, double angle, double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

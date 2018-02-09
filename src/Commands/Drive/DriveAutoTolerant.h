#pragma once

#include <Timer.h>
#include "CommandBase.h"

class DriveAutoTolerant: public CommandBase {
private:
	double distance;
	double angle;
	double speed;
	Timer done;
public:
	DriveAutoTolerant(double distance, double angle);
	DriveAutoTolerant(double distance, double angle, double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

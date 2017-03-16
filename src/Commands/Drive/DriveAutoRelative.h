#pragma once

#include "CommandBase.h"

class DriveAutoRelative: public CommandBase {
private:
	double distance;
	double distanceRelative;
	double angle;
	double angleRelative;
	double speed;
public:
	DriveAutoRelative(double distance, double angle);
	DriveAutoRelative(double distance, double angle, double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

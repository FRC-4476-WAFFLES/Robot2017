#pragma once

#include "CommandBase.h"

class DriveHalfRelative: public CommandBase {
private:
	double angle;
	double angleRelative;
	double speed;
	double percent_right;
public:
	DriveHalfRelative(double angle, double percent_right);
	DriveHalfRelative(double angle, double speed, double percent_right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

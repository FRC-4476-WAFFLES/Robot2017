#pragma once

#include "CommandBase.h"

class DriveHalf: public CommandBase {
private:
	double angle;
	double speed;
	double percent_right;
public:
	DriveHalf(double angle, double percent_right);
	DriveHalf(double angle, double speed, double percent_right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};











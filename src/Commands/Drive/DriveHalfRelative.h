#pragma once

#include "CommandBase.h"

class DriveHalfRelative: public CommandBase {
private:
	double angle;
	double angleRelative;
	double speed;
	int side;
public:
	DriveHalfRelative(double angle, int side);
	DriveHalfRelative(double angle, double speed, int side);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};











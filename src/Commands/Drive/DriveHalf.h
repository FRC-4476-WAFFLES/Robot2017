#pragma once

#include "CommandBase.h"

class DriveHalf: public CommandBase {
private:
	double angle;
	double speed;
	int side;
public:
	DriveHalf(double angle, int side);
	DriveHalf(double angle, double speed, int side);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};











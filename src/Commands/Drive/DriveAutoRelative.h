/*
 * DriveAutoRelative.h
 *
 *  Created on: Feb 27, 2016
 *      Author: Robotics-1
 */

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

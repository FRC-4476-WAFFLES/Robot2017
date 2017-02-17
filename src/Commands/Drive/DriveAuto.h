/*
 * DriveAuto.h
 *
 *  Created on: Feb 27, 2016
 *      Author: Robotics-1
 */

#ifndef DRIVE_AUTO_H_
#define DRIVE_AUTO_H_

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

#endif









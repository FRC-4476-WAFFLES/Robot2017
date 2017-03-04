#pragma once

#include "CommandBase.h"
#include "WPILib.h"

class ConveyorAuto: public CommandBase
{
private:
	double speed;
	double time;
	Timer done;
public:
	ConveyorAuto(double speed, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


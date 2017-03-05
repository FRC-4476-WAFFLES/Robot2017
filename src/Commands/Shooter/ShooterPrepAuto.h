#pragma once

#include "CommandBase.h"
#include "WPILib.h"

class ShooterPrepAuto: public CommandBase
{
private:
	Timer t;
public:
	ShooterPrepAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


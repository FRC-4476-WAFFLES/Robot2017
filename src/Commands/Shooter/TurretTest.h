#pragma once

#include "CommandBase.h"
#include "WPILib.h"

class TurretTest: public CommandBase
{
public:
	TurretTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

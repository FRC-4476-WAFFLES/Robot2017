#pragma once

#include "CommandBase.h"
#include "WPILib.h"

class TurretFudge: public CommandBase
{
public:
	TurretFudge();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


#pragma once

#include "CommandBase.h"
#include "WPILib.h"

class TurretDefault: public CommandBase
{
public:
	TurretDefault();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

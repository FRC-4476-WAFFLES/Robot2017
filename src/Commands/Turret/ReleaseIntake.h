#pragma once

#include "CommandBase.h"
#include "WPILib.h"

class ReleaseIntake: public CommandBase
{
public:
	ReleaseIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


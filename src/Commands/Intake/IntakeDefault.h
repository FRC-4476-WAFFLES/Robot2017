#pragma once

#include "CommandBase.h"
#include "WPILib.h"

class IntakeDefault: public CommandBase
{
public:
	IntakeDefault();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


#pragma once

#include "CommandBase.h"
#include "WPILib.h"

class ShooterPrep: public CommandBase
{
public:
	ShooterPrep();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


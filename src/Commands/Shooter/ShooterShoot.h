#pragma once

#include "CommandBase.h"
#include "WPILib.h"

class ShooterShoot: public CommandBase
{
public:
	ShooterShoot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


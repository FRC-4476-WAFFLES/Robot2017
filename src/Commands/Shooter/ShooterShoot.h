#pragma once

#include "CommandBase.h"

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


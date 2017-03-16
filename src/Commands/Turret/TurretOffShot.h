#pragma once

#include "CommandBase.h"

class TurretOffShot: public CommandBase
{
public:
	TurretOffShot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


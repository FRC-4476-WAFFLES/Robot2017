#pragma once

#include "CommandBase.h"

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


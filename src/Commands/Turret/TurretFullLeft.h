#pragma once

#include "CommandBase.h"
#include "WPILib.h"

class TurretFullLeft: public CommandBase
{
public:
	TurretFullLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


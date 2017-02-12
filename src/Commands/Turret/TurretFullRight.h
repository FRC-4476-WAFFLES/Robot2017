#pragma once

#include "CommandBase.h"
#include "WPILib.h"

class TurretFullRight: public CommandBase
{
public:
	TurretFullRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


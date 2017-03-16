#pragma once

#include "CommandBase.h"

class TurretCenterShot: public CommandBase
{
public:
	TurretCenterShot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


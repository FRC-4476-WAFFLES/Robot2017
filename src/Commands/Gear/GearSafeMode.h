#pragma once

#include "CommandBase.h"

class GearSafeMode : public CommandBase {
public:
	GearSafeMode();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


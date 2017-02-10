#pragma once

#include "CommandBase.h"

class GearToggle : public CommandBase {
public:
	GearToggle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int Toggle = 0;
};


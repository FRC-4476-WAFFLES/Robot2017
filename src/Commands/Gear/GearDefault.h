#pragma once

#include "CommandBase.h"

class GearDefault : public CommandBase {
public:
	GearDefault();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


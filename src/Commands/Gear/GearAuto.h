#pragma once

#include <Timer.h>
#include "CommandBase.h"

class GearAuto : public CommandBase {
public:
	GearAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	Timer t;
};

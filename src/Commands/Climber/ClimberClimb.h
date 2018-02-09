#pragma once

#include "CommandBase.h"
#include <Timer.h>

class ClimberClimb : public CommandBase {
public:
	ClimberClimb();
	void drivet(double left);
	void drive(double right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	Timer t;
};

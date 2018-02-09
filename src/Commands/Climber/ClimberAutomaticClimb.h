#pragma once

#include "CommandBase.h"

class ClimberAutomaticClimb : public CommandBase {
public:
	ClimberAutomaticClimb();
	void drivet(double left);
	void drive(double right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

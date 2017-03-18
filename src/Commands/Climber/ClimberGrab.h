#pragma once

#include "CommandBase.h"

class ClimberGrab : public CommandBase {
public:
	ClimberGrab();
	void drivet(double left);
	void drive(double right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

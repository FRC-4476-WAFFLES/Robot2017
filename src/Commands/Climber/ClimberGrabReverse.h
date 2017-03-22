#pragma once

#include "CommandBase.h"

class ClimberGrabReverse : public CommandBase {
public:
	ClimberGrabReverse();
	void drivet(double left);
	void drive(double right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

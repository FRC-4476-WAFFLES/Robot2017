#pragma once

#include "CommandBase.h"

class ClimberStop : public CommandBase {
public:
	ClimberStop();
	void drivet(double left);
	void drive(double right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#pragma once

#include "CommandBase.h"

class ClimberDefault : public CommandBase {
public:
	ClimberDefault();
	void drivet(double left);
	void drive(double right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

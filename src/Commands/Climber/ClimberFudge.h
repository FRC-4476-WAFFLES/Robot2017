#pragma once

#include "../../CommandBase.h"

class ClimberFudge : public CommandBase {
public:
	ClimberFudge();
	void drivet(double left);
	void drive(double right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#pragma once

#include "../../CommandBase.h"

class IntakeDefault : public CommandBase {
public:
	IntakeDefault();
	void drivet(double left);
	void drive(double right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

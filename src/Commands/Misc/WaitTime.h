#pragma once

#include <Timer.h>
#include "CommandBase.h"

class WaitTime: public CommandBase {
private:
	Timer* timer;
	double duration;
public:
	WaitTime(double duration);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

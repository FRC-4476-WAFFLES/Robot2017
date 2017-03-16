#pragma once

#include <Timer.h>
#include "CommandBase.h"

class GearAutoUltrasonic : public CommandBase {
public:
	GearAutoUltrasonic();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	Timer t;
};

#pragma once

#include "CommandBase.h"

class GearOpenAuto : public CommandBase {
public:
	GearOpenAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

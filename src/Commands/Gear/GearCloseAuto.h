#pragma once

#include "CommandBase.h"

class GearCloseAuto : public CommandBase {
public:
	GearCloseAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

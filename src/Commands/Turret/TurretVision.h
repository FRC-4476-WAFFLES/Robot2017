#pragma once

#include <CommandBase.h>

class TurretVision: public CommandBase {
public:
	TurretVision();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

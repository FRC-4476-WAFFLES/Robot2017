#pragma once

#include "CommandBase.h"

class ShooterDefault: public CommandBase
{
public:
	ShooterDefault();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


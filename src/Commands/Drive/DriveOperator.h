#pragma once

#include "CommandBase.h"

class DriveOperator: public CommandBase
{
public:
	DriveOperator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

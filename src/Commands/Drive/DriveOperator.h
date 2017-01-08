#ifndef DRIVE_OPERATOR_H
#define DRIVE_OPERATOR_H

#include "CommandBase.h"
#include "WPILib.h"

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

#endif

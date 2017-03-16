#pragma once

#include "CommandBase.h"

class DrawerBumper : public CommandBase {
public:
	DrawerBumper();
	void drivet(double left);
	void drive(double right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

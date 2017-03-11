#pragma once

#include "../../CommandBase.h"

class DrawerOut : public CommandBase {
public:
	DrawerOut();
	void drivet(double left);
	void drive(double right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

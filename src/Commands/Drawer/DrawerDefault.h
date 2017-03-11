#pragma once

#include "../../CommandBase.h"

class DrawerDefault : public CommandBase {
public:
	DrawerDefault();
	void drivet(double left);
	void drive(double right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

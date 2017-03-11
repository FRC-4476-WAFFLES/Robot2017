#pragma once

#include "../../CommandBase.h"

class DrawerIn : public CommandBase {
public:
	DrawerIn();
	void drivet(double left);
	void drive(double right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

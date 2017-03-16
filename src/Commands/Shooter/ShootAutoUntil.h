#pragma once

#include "CommandBase.h"

class ShootAutoUntil: public CommandBase
{
private:
    double time;
    Timer &timer;
public:
	ShootAutoUntil(Timer&, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

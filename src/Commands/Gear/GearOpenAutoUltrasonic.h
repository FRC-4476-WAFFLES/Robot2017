#pragma once

#include "CommandBase.h"

class GearOpenAutoUltrasonic : public CommandBase {
public:
	GearOpenAutoUltrasonic();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double pos;
};

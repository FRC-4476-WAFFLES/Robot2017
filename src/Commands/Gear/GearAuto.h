#ifndef GearAuto_H
#define GearAuto_H

#include "CommandBase.h"

class GearAuto : public CommandBase {
public:
	GearAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	Timer t;
};

#endif  // gearAuto_H

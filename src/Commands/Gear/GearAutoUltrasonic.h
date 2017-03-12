#ifndef GearAutoUltrasonic_H
#define GearAutoUltrasonic_H

#include "CommandBase.h"

class GearAutoUltrasonic : public CommandBase {
public:
	GearAutoUltrasonic();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	Timer t;
};

#endif  // GearAutoUltrasonic_H

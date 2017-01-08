#ifndef WAIT_TIME_H_
#define WAIT_TIME_H_

#include <CommandBase.h>
#include "WPILib.h"

class WaitTime: public CommandBase {
private:
	Timer* timer;
	double duration;
public:
	WaitTime(double duration);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

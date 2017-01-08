#ifndef WAIT_TRIGGER_H_
#define WAIT_TRIGGER_H_

#include <CommandBase.h>
#include "WPILib.h"

class WaitTrigger: public CommandBase {
private:

public:
	WaitTrigger();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

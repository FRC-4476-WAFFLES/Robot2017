#pragma once

#include <CommandBase.h>

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

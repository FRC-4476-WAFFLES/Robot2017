#ifndef CancelGearCommand_H
#define CancelGearCommand_H

#include "CommandBase.h"

class CancelGearCommand : public CommandBase {
public:
	CancelGearCommand();
	void Initialize();
	bool IsFinished() {
		return true;
	}
};

#endif  // CancelGearCommand_H

#pragma once

#include <Joystick.h>
#include <Buttons/Trigger.h>

class POVTrigger : public Trigger {
private:
	Joystick *joystick;
	int angle;
public:
	POVTrigger(Joystick*, int angle);
	bool Get() override;
};


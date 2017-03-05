#pragma once

#include <Joystick.h>
#include <Buttons/Trigger.h>

class TurretTrigger : public Trigger {
private:
	Joystick *joystick;
public:
	TurretTrigger(Joystick*);
	bool Get() override;
};


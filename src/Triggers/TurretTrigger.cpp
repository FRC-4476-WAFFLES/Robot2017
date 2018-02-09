#include "TurretTrigger.h"
#include "OI.h"

TurretTrigger::TurretTrigger(Joystick *joystick):
	joystick(joystick)
{

}

bool TurretTrigger::Get() {
	return !OI::DriveDeadzone(joystick->GetRawAxis(2));
}

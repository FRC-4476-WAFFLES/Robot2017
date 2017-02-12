#include "POVTrigger.h"

POVTrigger::POVTrigger(Joystick *joystick, int angle):
	joystick(joystick), angle(angle)
{

}

bool POVTrigger::Get() {
	return joystick->GetPOV(0) == angle;
}


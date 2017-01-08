#include "WaitTrigger.h"

////////////////DISCRIPTION//////////////////
// Waits for a button to be pressed on the controller

WaitTrigger::WaitTrigger():
	CommandBase("DriveAuto")
{

}

void WaitTrigger::Initialize() {}
void WaitTrigger::Execute() {}

bool WaitTrigger::IsFinished() {
	return oi->operatorController->GetRawButton(OI::BumperBottomRight);
}

void WaitTrigger::End() {}
void WaitTrigger::Interrupted() {}


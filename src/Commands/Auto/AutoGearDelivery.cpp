#include "AutoDoNothing.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Auto/ShootAuto.h"
#include "Commands/Shooter/Intake.h"
#include "Commands/Shooter/ExtentionOut.h"

AutoDoNothing::AutoDoNothing()
{
	SetTimeout(15.0);
	AddSequential(new WaitTime(1.0));

}

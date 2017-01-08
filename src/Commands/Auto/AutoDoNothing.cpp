#include "AutoDoNothing.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"

AutoDoNothing::AutoDoNothing()
{
	SetTimeout(15.0);
	AddSequential(new WaitTime(1.0));

}

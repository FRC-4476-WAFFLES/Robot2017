#include <Commands/Auto/AutoRightGearDelivery.h>
#include "AutoGearDelivery.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"

AutoRightGearDelivery::AutoRightGearDelivery() {

	SetTimeout(15.0);
	AddSequential(new DriveAuto(0,0));
	AddSequential(new DriveAuto(0,-45));
	AddSequential(new DriveAuto(0,-45));


}

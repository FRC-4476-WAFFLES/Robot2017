#include "AutoRightGearDelivery.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Drive/DriveAutoRelative.h"
#include "Commands/Drive/DriveHalfRelative.h"

AutoRightGearDelivery::AutoRightGearDelivery() {

	SetTimeout(15.0);
	AddSequential(new DriveAuto(3.4,0));
	AddSequential(new DriveHalfRelative(-45, 0.0));
	AddSequential(new DriveAutoRelative(1.0, 0.0));
}

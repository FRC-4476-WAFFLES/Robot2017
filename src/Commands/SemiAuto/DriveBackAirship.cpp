#include "DriveBackAirship.h"
#include "Commands/Drive/DriveHalfRelative.h"
#include "Commands/Drive/DriveAutoRelative.h"
DriveBackAirship::DriveBackAirship() {
	AddSequential(new DriveAutoRelative(-76.83333333333333,0));
	//AddSequential(new DriveHalfRelative(-90.0,1));

	//-153.6666666666667
}

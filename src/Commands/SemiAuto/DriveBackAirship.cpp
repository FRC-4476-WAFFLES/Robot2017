#include "DriveBackAirship.h"
#include "Commands/Drive/DriveHalfRelative.h"
#include "Commands/Drive/DriveAutoRelative.h"
DriveBackAirship::DriveBackAirship(bool right) {
	SetTimeout(2.0);
	AddSequential(new DriveAutoRelative(-1,0,1));
	if(right)
		AddSequential(new DriveHalfRelative(90.0,1));
	else
		AddSequential(new DriveHalfRelative(-90.0,1));

	//-153.6666666666667
}

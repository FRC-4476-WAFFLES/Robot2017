#include "DriveBackLoadStation.h"
#include "Commands/Drive/DriveHalfRelative.h"
#include "Commands/Drive/DriveAutoRelative.h"
DriveBackLoadStation::DriveBackLoadStation() {
	SetTimeout(2.0);
	AddSequential(new DriveAutoRelative(-0.5,0,1));
	AddSequential(new DriveHalfRelative(+135.0,2));

	//-153.6666666666667
}

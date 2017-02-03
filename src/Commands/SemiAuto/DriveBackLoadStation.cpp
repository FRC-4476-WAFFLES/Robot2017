#include "DriveBackLoadStation.h"
#include "Commands/Drive/DriveHalfRelative.h"
#include "Commands/Drive/DriveAutoRelative.h"
DriveBackLoadStation::DriveBackLoadStation() {
	AddSequential(new DriveAutoRelative(0.5,0));
	AddSequential(new DriveHalfRelative(+135.0,2));

	//-153.6666666666667
}

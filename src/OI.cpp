/**
 * OI is a class that is used to setup user input to the robot.
 */

#include "OI.h"
#include "Commands/SemiAuto/DriveBackAirship.h"
#include "Commands/SemiAuto/DriveBackLoadStation.h"
OI::OI()
{
	/*

	*/
	//Options between button types: WhenPressed, WhileHeld, ToggleWhenPressed
	// Process operator interface input here.

	// Joystick port declarations
	joystickRight = new Joystick(0);
	joystickLeft = new Joystick(1);
	operatorController = new Joystick(2);

	Button* Airship = new JoystickButton(joystickRight,3);
	Airship->WhenReleased(new DriveBackAirship);

	Button* Load = new JoystickButton(joystickLeft,3);
	Load->WhenReleased(new DriveBackLoadStation);
}

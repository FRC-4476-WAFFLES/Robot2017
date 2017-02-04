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

	Button* Airship1 = new JoystickButton(joystickRight,11);
	Airship1->WhenReleased(new DriveBackAirship);
	Button* Airship2 = new JoystickButton(joystickRight,10);
	Airship2->WhenReleased(new DriveBackAirship);

	Button* Load1 = new JoystickButton(joystickLeft,6);
	Load1->WhenReleased(new DriveBackLoadStation);
	Button* Load2 = new JoystickButton(joystickLeft,7);
	Load2->WhenReleased(new DriveBackLoadStation);
}

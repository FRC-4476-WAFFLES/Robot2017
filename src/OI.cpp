/**
 * OI is a class that is used to setup user input to the robot.
 */

#include "OI.h"

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
}

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
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	operatorController = new Joystick(2);

	Button* Airship1 = new JoystickButton(joystickLeft, 8);
	Button* Airship2 = new JoystickButton(joystickLeft, 9);
	Button* Airship3 = new JoystickButton(joystickRight, 8);
	Button* Airship4 = new JoystickButton(joystickRight, 9);
	Airship1->WhenReleased(new DriveBackLoadStation);
	Airship2->WhenReleased(new DriveBackLoadStation);
	Airship3->WhenReleased(new DriveBackLoadStation);
	Airship4->WhenReleased(new DriveBackLoadStation);

	Button* Load1 = new JoystickButton(joystickLeft, 6);
	Button* Load2 = new JoystickButton(joystickLeft, 7);
	Button* Load3 = new JoystickButton(joystickRight, 10);
	Button* Load4 = new JoystickButton(joystickRight, 11);
	Load1->WhenReleased(new DriveBackAirship(false));
	Load2->WhenReleased(new DriveBackAirship(false));
	Load3->WhenReleased(new DriveBackAirship(true));
	Load4->WhenReleased(new DriveBackAirship(true));
}

#pragma once

#include <Joystick.h>
#include <PowerDistributionPanel.h>

class OI
{
public:
	void prints();
	static bool DriveDeadzone(double x);
	bool DriveActive();
	enum OperatorButton {
		X=1,
		A=2,
		B=3,
		Y=4,
		BumperTopLeft=5,
		BumperTopRight=6,
		BumperBottomLeft=7,
		BumperBottomRight=8,
		Back=9,
		Start=10,
	};

	OI();
	Joystick* joystickLeft;
	Joystick* joystickRight;
	Joystick* operatorController;

	PowerDistributionPanel pdp;
};

#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
public:
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
};

#endif

#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// PWM Motors
constexpr int SHOOTER_TURRET = 4;
constexpr int INTAKE_ROLLER = 6;

// CAN Motors
constexpr int SHOOTER_ROLLER = 0;

// Analog Inputs

// Digital Inputs
constexpr int DRIVE_ENCODER_A = 0;//
constexpr int DRIVE_ENCODER_B = 1;//
constexpr int DRIVE_ENCODER_C = 2;//
constexpr int DRIVE_ENCODER_D = 3;


#endif



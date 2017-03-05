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

constexpr int DRIVE_RIGHT_1 = 0;
constexpr int DRIVE_RIGHT_2 = 1;
constexpr int DRIVE_RIGHT_3 = 2;
constexpr int DRIVE_LEFT_1 = 3;
constexpr int DRIVE_LEFT_2 = 4;
constexpr int DRIVE_LEFT_3 = 5;

constexpr int INTAKE_ROLLER = 7;

constexpr int GEAR_LEFT = 8;
constexpr int GEAR_RIGHT = 9;

// CAN Motors
constexpr int TOP_CLIMBER_ROLLER = 3;
constexpr int TOP_CLIMBER_SLAVE= 4;

constexpr int BALL_CONVEYOR = 1;
// Analog Inputs

// Digital Inputs
constexpr int DRIVE_ENCODER_A = 8;//
constexpr int DRIVE_ENCODER_B = 9;//
constexpr int DRIVE_ENCODER_C = 2;//
constexpr int DRIVE_ENCODER_D = 3;



#endif



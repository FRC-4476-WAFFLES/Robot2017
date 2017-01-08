#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// PID Motors
constexpr int DRIVE_MOTOR_RIGHT_FRONT = 0;
constexpr int DRIVE_MOTOR_RIGHT_BACK = 1;
constexpr int DRIVE_MOTOR_LEFT_FRONT = 2;
constexpr int DRIVE_MOTOR_LEFT_BACK = 3;


// Analog Inputs

// Digital Inputs

constexpr int DRIVE_ENCODER_A = 0;//
constexpr int DRIVE_ENCODER_B = 1;//
constexpr int DRIVE_ENCODER_C = 2;//
constexpr int DRIVE_ENCODER_D = 3;


#endif



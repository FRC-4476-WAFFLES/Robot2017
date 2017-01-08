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
constexpr int BOTTOM_ROLLER = 4;//4or5
constexpr int TOP_ROLLER = 5;//4or5
constexpr int TOP_SHOOTER = 6;
constexpr int BOTTOM_SHOOTER = 7;
constexpr int PIVOT = 8;
constexpr int EXTENSION = 9;

// Analog Inputs

// Relay
constexpr int FLASHLIGHT = 0;

// Digital Inputs
constexpr int BOTTOM_SHOOTER_E = 0; // And 1
constexpr int EXTENSION_E = 2;
constexpr int TOP_SHOOTER_E = 3; // And 4
constexpr int DRIVE_ENCODER_A = 5;//
constexpr int DRIVE_ENCODER_B = 6;//
constexpr int PIVOT_E = 7;//
//constexpr int BOTTOM_HARDSTOP = 8;//

#endif

// CONSTANTS
constexpr double SHOOTER_ENCODER_COEFFICIENT = 1800.0;

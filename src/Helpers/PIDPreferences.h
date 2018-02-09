#pragma once
#include <string>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/Phoenix.h>
#include <Preferences.h>

void UpdatePID(std::string name, TalonSRX *talon, double p, double i, double d, double f);
void UpdatePID(std::string name, TalonSRX *talon, double p, double i, double d);
void UpdatePID(std::string name, TalonSRX *talon);

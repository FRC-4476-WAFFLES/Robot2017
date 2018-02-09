#pragma once
#include <string>
#include <CANTalon.h>
#include <Preferences.h>

void UpdatePID(std::string name, CANTalon *talon, double p, double i, double d, double f);
void UpdatePID(std::string name, CANTalon *talon, double p, double i, double d);
void UpdatePID(std::string name, CANTalon *talon);

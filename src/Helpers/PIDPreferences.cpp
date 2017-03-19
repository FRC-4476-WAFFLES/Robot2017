#include "Helpers/PIDPreferences.h"

double UpdateSinglePreference(std::string name, double v) {
    if(!Preferences::GetInstance()->ContainsKey(name)) {
        Preferences::GetInstance()->PutDouble(name, v);
    }
    return Preferences::GetInstance()->GetDouble(name, v);
}

void UpdatePID(std::string name, CANTalon *talon, double p, double i, double d, double f) {
    talon->SelectProfileSlot(0);
	talon->SetP(UpdateSinglePreference(name + " P", p));
	talon->SetI(UpdateSinglePreference(name + " I", i));
	talon->SetD(UpdateSinglePreference(name + " D", d));
    talon->SetF(UpdateSinglePreference(name + " F", f));
}

void UpdatePID(std::string name, CANTalon *talon, double p, double i, double d) {
    UpdatePID(name, talon, p, i, d, 0.0);
}

void UpdatePID(std::string name, CANTalon *talon) {
    UpdatePID(name, talon, 0.0, 0.0, 0.0, 0.0);
}
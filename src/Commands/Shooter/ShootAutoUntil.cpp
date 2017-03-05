#include "ShootAutoUntil.h"

ShootAutoUntil::ShootAutoUntil(Timer &timer, double time):
	CommandBase("ShootAutoUntil"),
	time(time), timer(timer)
{
    Requires(shooter.get());
}

void ShootAutoUntil::Initialize() {
    
}

void ShootAutoUntil::Execute() {
    shooter->RunLoad();
    shooter->SetSpeed(turret->Determined_Speed);
}

bool ShootAutoUntil::IsFinished() {
    return timer.HasPeriodPassed(time);
}

void ShootAutoUntil::End() {
    shooter->StopLoad();
	shooter->SetPower(0.0);
}

void ShootAutoUntil::Interrupted() {
    shooter->StopLoad();
	shooter->SetPower(0.0);
}

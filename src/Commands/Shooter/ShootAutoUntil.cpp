#include "ShootAutoUntil.h"

ShootAutoUntil::ShootAutoUntil(Timer &timer, double time):
	CommandBase("ShootAutoUntil"),
	time(time), timer(timer)
{
    Requires(shooter.get());
    Requires(intake.get());
}

void ShootAutoUntil::Initialize() {
    
}

void ShootAutoUntil::Execute() {
    shooter->RunLoad();
    shooter->SetSpeed(turret->Determined_Speed);
	intake->IntakeRollers->SetSpeed(-1.0);
	intake->BallConveyor->Set(-1.0);
}

bool ShootAutoUntil::IsFinished() {
    return timer.HasPeriodPassed(time);
}

void ShootAutoUntil::End() {
    shooter->StopLoad();
	shooter->SetPower(0.0);
	intake->IntakeRollers->SetSpeed(0.0);
	intake->BallConveyor->Set(0.0);
}

void ShootAutoUntil::Interrupted() {
    shooter->StopLoad();
	shooter->SetPower(0.0);
}

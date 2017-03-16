#include "Commands/Gear/GearOpenAuto.h"
#include "Subsystems/GearSubsystem.h"

GearOpenAuto::GearOpenAuto():
	CommandBase("GearOpenAuto") {
	Requires(gear.get());
}

void GearOpenAuto::Initialize() {
	gear->is_open = true;
}

void GearOpenAuto::Execute() {
	gear->Persist();
}

bool GearOpenAuto::IsFinished() {
	return true;
}

void GearOpenAuto::End() {

}

void GearOpenAuto::Interrupted() {

}

#include "GearCloseAuto.h"

GearCloseAuto::GearCloseAuto():
	CommandBase("GearCloseAuto") {
	Requires(gear.get());
}

void GearCloseAuto::Initialize() {
	gear->is_open = false;
}

void GearCloseAuto::Execute() {
	gear->Persist();
}

bool GearCloseAuto::IsFinished() {
	return true;
}

void GearCloseAuto::End() {

}

void GearCloseAuto::Interrupted() {

}

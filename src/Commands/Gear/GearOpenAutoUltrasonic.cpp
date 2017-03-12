#include <Commands/Gear/GearOpenAutoUltrasonic.h>


GearOpenAutoUltrasonic::GearOpenAutoUltrasonic():
	CommandBase("GearOpenAutoUltrasonic") {
	Requires(drive.get());
	Requires(gear.get());
}

void GearOpenAutoUltrasonic::Initialize() {
	gear->is_open = true;
}

void GearOpenAutoUltrasonic::Execute() {
	drive->DriveToGearWall();
	gear->Persist();
}

bool GearOpenAutoUltrasonic::IsFinished() {
	return true;
}

void GearOpenAutoUltrasonic::End() {

}

void GearOpenAutoUltrasonic::Interrupted() {

}

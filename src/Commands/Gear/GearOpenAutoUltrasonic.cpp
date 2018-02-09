#include "Commands/Gear/GearOpenAutoUltrasonic.h"
#include "Subsystems/GearSubsystem.h"
#include "Subsystems/DriveSubsystem.h"

GearOpenAutoUltrasonic::GearOpenAutoUltrasonic():
	CommandBase("GearOpenAutoUltrasonic") {
	Requires(drive.get());
	Requires(gear.get());
	pos = drive->angle();
}

void GearOpenAutoUltrasonic::Initialize() {
	gear->is_open = true;
	pos = drive->angle();
}

void GearOpenAutoUltrasonic::Execute() {
	drive->DriveToGearWall(pos);
	gear->Persist();
}

bool GearOpenAutoUltrasonic::IsFinished() {
	return drive->IsAtWall(); // TODO: back up?
}

void GearOpenAutoUltrasonic::End() {

}

void GearOpenAutoUltrasonic::Interrupted() {

}

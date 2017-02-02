#include "networktables/NetworkTable.h"
#include "vision.hpp"
#include "run_result.hpp"

int main() {
  NetworkTable::SetClientMode();
  NetworkTable::SetTeam(4476);
  NetworkTable::SetUpdateRate(0.05);
  std::shared_ptr<NetworkTable> table = NetworkTable::GetTable("CameraTable");
  table->SetDefaultBoolean("Found", false);

  // Setup camera and get ready for processing
  Vision vision(-1);

  while(true) {
    RunResult partial = vision.process_frame();
    table->PutBoolean("Found", partial.found);
    table->PutNumber("Distance", partial.distance);
    table->PutNumber("Angle", partial.angle);
  }
}

struct RunResult {
  int32_t found;
  float angle;
  float distance;
  float duration;
} most_recent_result;

uint8_t* to_bytes(RunResult* result) {
  return reinterpret_cast<uint8_t*>(result);
}

RunResult* from_bytes(uint8_t bytes[32]) {
  return reinterpret_cast<RunResult*>(bytes);
}

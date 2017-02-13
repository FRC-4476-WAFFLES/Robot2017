#pragma once
#include <stdint.h>

struct RunResult {
  uint8_t found;
  float angle;
  float distance;
  float duration;
};

char* to_bytes(RunResult* result);
RunResult* from_bytes(char bytes[sizeof(RunResult)]);

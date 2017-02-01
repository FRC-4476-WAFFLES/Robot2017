#include "run_result.hpp"

char* to_bytes(RunResult* result) {
  return reinterpret_cast<char*>(result);
}

RunResult* from_bytes(char bytes[sizeof(RunResult)]) {
  return reinterpret_cast<RunResult*>(bytes);
}

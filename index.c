#include "src/logger.h"

int main() {
  set_log_level(DEBUG);
  logger(DEBUG, "Hello world!");
  return 0;
}

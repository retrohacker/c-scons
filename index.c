#include "src/logger.h"

int main() {
  set_log_output(stdout);
  set_log_level(DEBUG);
  logger(DEBUG, "Hello world!\n");
  return 0;
}

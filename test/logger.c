#include "lib/test.h"
#include "src/logger.h"

#include <stdio.h>
#include <string.h>

int t1();
int t2();

int main() {
  return t1() | t2();
}

int t1() {
  test *t = new_test("Logger: Should default to ERROR");
  FILE *output = fopen("./output.tmp", "w");
  set_log_output(output);
  logger(DEBUG, "a");
  logger(WARN, "a");
  logger(ERROR, "a");
  fclose(output);
  output = fopen("./output.tmp", "r");
  char c[5];
  fgets(c, 5, output);
  fclose(output);
  remove("./output.tmp");
  equal(t, "%zd", "Expected to log %zd time and saw %zd", 1, strlen(c));
  return done(t);
}

int t2() {
  test *t = new_test("Logger: Should handle changing log levels");
  FILE *output = fopen("./output.tmp", "w");
  set_log_output(output);
  set_log_level(ERROR);
  logger(DEBUG, "a");
  logger(WARN, "a");
  logger(ERROR, "a"); // Should output 1
  set_log_level(WARN);
  logger(DEBUG, "a");
  logger(WARN, "a");
  logger(ERROR, "a"); // Should output 2
  set_log_level(DEBUG);
  logger(DEBUG, "a");
  logger(WARN, "a");
  logger(ERROR, "a"); // Should output 3
  set_log_level(OFF);
  logger(DEBUG, "a");
  logger(WARN, "a");
  logger(ERROR, "a"); // Should output 0
  fclose(output); // Should have logged 6 times
  output = fopen("./output.tmp", "r");
  char c[7];
  fgets(c, 7, output);
  fclose(output); // Should have logged 6 times
  remove("./output.tmp");
  equal(t, "%zd", "Expected to log %zd time and saw %zd", 6, strlen(c));
  return done(t);
}

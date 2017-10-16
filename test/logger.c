#include "lib/test.h"
#include "src/logger.h"

#include <stdio.h>
#include <string.h>

int t1();
int t2();
int t3();

int main() {
  return t1() | t2() | t3();
}

int t1() {
  test *t = new_test("Logger: Should default to ERROR");
  FILE *output = fopen("./output.tmp", "w");
  set_log_output(output);
  logger(DEBUG, "a");
  logger(WARN, "b");
  logger(ERROR, "c");
  fclose(output);
  output = fopen("./output.tmp", "r");
  char c[5];
  fgets(c, 5, output);
  fclose(output);
  remove("./output.tmp");
  equal(t, "%s", "Expected to log %s and saw %s", "c", c);
  return done(t);
}

int t2() {
  test *t = new_test("Logger: Should handle changing log levels");
  FILE *output = fopen("./output.tmp", "w");
  set_log_output(output);
  set_log_level(ERROR);
  logger(DEBUG, "a");
  logger(WARN, "b");
  logger(ERROR, "c");
  set_log_level(WARN);
  logger(DEBUG, "d");
  logger(WARN, "e");
  logger(ERROR, "f");
  set_log_level(DEBUG);
  logger(DEBUG, "g");
  logger(WARN, "h");
  logger(ERROR, "i");
  set_log_level(OFF);
  logger(DEBUG, "j");
  logger(WARN, "k");
  logger(ERROR, "l");
  fclose(output);
  output = fopen("./output.tmp", "r");
  char c[7];
  fgets(c, 7, output);
  fclose(output);
  remove("./output.tmp");
  equal(t, "%s", "Expected to log %s and saw %s", "cefghi", c);
  return done(t);
}

int t3() {
  test *t = new_test("Logger: Should be safe to call without output stream");
  set_log_output(NULL);
  logger(ERROR, "a");
  ok(t, "%d", "Compiled", 1);
  return done(t);
}

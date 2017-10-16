# To run

```
$ scons -s test
# Logger: Should default to ERROR
  [ OK ] - Expected to log c and saw c
# Logger: Should handle changing log levels
  [ OK ] - Expected to log cefghi and saw cefghi
# Logger: Should be safe to call without output stream
  [ OK ] - Compiled
File 'src/logger.c'
Lines executed:100.00% of 17
Creating 'logger.c.gcov'
```

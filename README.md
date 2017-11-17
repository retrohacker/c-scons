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

# Setup on OSx

OSx ships with a fake `gcc` and `gcov` utility that actually run clang. This build doesn't support clang.

To setup OSx:

```
$ brew install gcc
$ brew install gcovr
$ cd /usr/local/bin
$ # For each gcc-*-7 and gcov-*-7 file, alias to remove the suffix. I.E.:
$ ln -s ./gcc-7 ./gcc
$ ln -s ./gcc-ar-7 ./gcc-ar
```

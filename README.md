Test project for https://github.com/stardot/beebasm/issues/36.

Run `make`.

# OS X result

`123A` reads as an int with the value `123`, and the input position is
left on the A. `123A` does not read as a double at all.

```
c++ --version
Apple LLVM version 9.0.0 (clang-900.0.39.2)
Target: x86_64-apple-darwin16.7.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
c++ -std=c++14 -Wall -O0 -g -o main ./main.cpp
./main
input line: ``123''
tellg before: 0 (00)
result: 123
tellg after: 18446744073709551615 (0ffffffffffffffff)
input line: ``123''
tellg before: 0 (00)
result: 123.000000
tellg after: 18446744073709551615 (0ffffffffffffffff)
input line: ``123A''
tellg before: 0 (00)
result: 123
tellg after: 3 (03)
input line: ``123A''
tellg before: 0 (00)
result: 0.000000
tellg after: 18446744073709551615 (0ffffffffffffffff)
```

# Linux result

`123A` reads as an int or double with the value `123`, and the input
position is left on the `A`.

```
c++ --version
c++ (Ubuntu 5.5.0-12ubuntu1~16.04) 5.5.0 20171010
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

c++ -std=c++14 -Wall -O0 -g -o main ./main.cpp
./main
input line: ``123''
tellg before: 0 (00)
result: 123
tellg after: 18446744073709551615 (0ffffffffffffffff)
input line: ``123''
tellg before: 0 (00)
result: 123.000000
tellg after: 18446744073709551615 (0ffffffffffffffff)
input line: ``123A''
tellg before: 0 (00)
result: 123
tellg after: 3 (03)
input line: ``123A''
tellg before: 0 (00)
result: 123.000000
tellg after: 3 (03)
```

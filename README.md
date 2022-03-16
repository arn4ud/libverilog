# libverilog

A structural verilog reader & writer.

## Getting Started

```
git clone https://github.com/arn4ud/libverilog.git
cd libverilog        # Main directory of the cloned repository.
mkdir build          # Create a directory to hold the build output.
cd build
cmake ..             # Generate makefiles
make
```

## License

libverilog is licensed under the terms of the Apache license.
See [LICENSE](LICENSE) for more information.

## Coding Style

To keep the source consistent, readable, diffable and easy to merge, all code is
expected to conform to the [C++ Core Guidelines](
https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).

Use CamelCase for type names, UPPER_CASE for macros, and snake_case for
everyhting else.

```
#ifndef FOO_BAR_H_
#define FOO_BAR_H_

namespace foo {

class Bar {
public:
    void do_something();
};

}  // namespace foo

#endif  /* FOO_BAR_H_ */
```

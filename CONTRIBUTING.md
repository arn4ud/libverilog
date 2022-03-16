# How to Contribute to libverilog

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

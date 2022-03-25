set(verilog_tests
  VerilogTest0.cpp
  VerilogTest1.cpp
  VerilogTest2.cpp
)

add_executable(verilogTests ${verilog_tests})

target_link_libraries(verilogTests verilog gtest gmock gtest_main)
target_compile_definitions(verilogTests PRIVATE VERILOG_TEST_PATH="${CMAKE_CURRENT_SOURCE_DIR}")


gtest_discover_tests(verilogTests)
#include "gtest/gtest.h"

#include "verilog_reader.h"


TEST(VerilogTest2, test) {
    std::filesystem::path test2Path(VERILOG_TEST_PATH);
    test2Path /= "files";
    test2Path /= "test2.v";
    verilog::VerilogReader reader;
    reader.read(test2Path);
}
#include "gtest/gtest.h"

#include "verilog_reader.h"


TEST(VerilogTest1, test) {
    std::filesystem::path test1Path(VERILOG_TEST_PATH);
    test1Path /= "files";
    test1Path /= "test1.v";
    verilog::VerilogReader reader;
    reader.read(test1Path);
}
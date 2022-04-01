#include "gtest/gtest.h"

#include "verilog_reader.h"


TEST(VerilogTest0, test) {
    std::filesystem::path test0Path(VERILOG_TEST_PATH);
    test0Path /= "files";
    test0Path /= "test0.v";
    verilog::VerilogReader reader;
    reader.read(test0Path);
}
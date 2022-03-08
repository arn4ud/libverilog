#include <cstdlib>
#include <verilog/verilog_lexer.h>
#include <verilog/verilog_parser.h>

class MyVerilogReader final : public verilog::VerilogReader {
public:
};

int main(int argc, char* argv[])
{
    verilog::VerilogLexer lexer;
    MyVerilogReader reader;
    verilog::VerilogParser parser(lexer, &reader);
    parser.parse();
    return 0;
}


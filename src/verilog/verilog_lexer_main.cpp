#include <iostream>
#include <verilog/verilog_lexer.h>

int main(int argc, char* argv[])
{
    verilog::VerilogLexer lexer;
    int t;
    verilog::VerilogParser::semantic_type yylval;
    while ((t = lexer.yylex(&yylval)) != 0) {
       std::cout
           << "lineno: " << lexer.lineno()
           << " token: " << t
//            << " text: " << yylval.sv
           << std::endl;
    }
    return 0;
}

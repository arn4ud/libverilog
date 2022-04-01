#include "verilog_lexer.h"
#include "verilog_parser.h"

#include <string>
#include <sstream>
#include "gtest/gtest.h"

namespace verilog {
namespace {

TEST(VerilogLexerTest, keywords) {
#if 0
    std::istringstream iss(R"(
        assign
        module
        endmodule
        input
        inout
        output
        wire
    )");
    VerilogLexer lexer;
    lexer.switch_streams(&iss, nullptr);

    VerilogParser::symbol_type symbol;
    symbol = lexer.get_token();
    EXPECT_EQ(symbol.type, VerilogParser::token::T_ASSIGN);
    symbol = lexer.get_token();
    EXPECT_EQ(symbol.type, VerilogParser::token::T_MODULE);
    symbol = lexer.get_token();
    EXPECT_EQ(symbol.type, VerilogParser::token::T_ENDMODULE);
    symbol = lexer.get_token();
    EXPECT_EQ(symbol.type, VerilogParser::token::T_INPUT);
    symbol = lexer.get_token();
    EXPECT_EQ(symbol.type, VerilogParser::token::T_INOUT);
    symbol = lexer.get_token();
    EXPECT_EQ(symbol.type, VerilogParser::token::T_OUTPUT);
    symbol = lexer.get_token();
    EXPECT_EQ(symbol.type, VerilogParser::token::T_WIRE);
    symbol = lexer.get_token();
    EXPECT_EQ(symbol.type, 0);
#endif
}

TEST(VerilogLexerTest, numbers) {
}

TEST(VerilogLexerTest, string) {
}

TEST(VerilogLexerTest, identifiers) {
#if 0
    std::istringstream iss(R"(
        foo _foo foo0123456789_$
        Foo _Foo Foo0123456789_$
        FOO _FOO FOO0123456789_$
        \foo:bar.baz[{(+=)}] x
        \FOO:BAR.BAZ[{(+=)}]
    )");
    VerilogLexer lexer;
    lexer.switch_streams(&iss, nullptr);

    verilog::VerilogParser::semantic_type lval;
    std::cout << "1\n";
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_SimpleIdentifier);
    std::cout << "2\n";
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_SimpleIdentifier);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_SimpleIdentifier);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_SimpleIdentifier);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_SimpleIdentifier);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_SimpleIdentifier);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_SimpleIdentifier);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_SimpleIdentifier);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_SimpleIdentifier);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_EscapedIdentifier);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_SimpleIdentifier);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_EscapedIdentifier);
    EXPECT_EQ(lexer.yylex(&lval), 0);
#endif
}

TEST(VerilogLexerTest, characters) {
}

}  // namespace
}  // namespace verilog

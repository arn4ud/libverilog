#include "verilog_lexer.h"
#include "verilog_parser.h"

#include <string>
#include <sstream>
#include "gtest/gtest.h"

namespace verilog {
namespace {

TEST(VerilogLexerTest, keywords) {
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

    verilog::VerilogParser::semantic_type lval;
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_ASSIGN);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_MODULE);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_ENDMODULE);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_INPUT);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_INOUT);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_OUTPUT);
    EXPECT_EQ(lexer.yylex(&lval), VerilogParser::token::T_WIRE);
    EXPECT_EQ(lexer.yylex(&lval), 0);
}

TEST(VerilogLexerTest, numbers) {
}

TEST(VerilogLexerTest, string) {
}

TEST(VerilogLexerTest, identifiers) {
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
}

TEST(VerilogLexerTest, characters) {
}

}  // namespace
}  // namespace verilog

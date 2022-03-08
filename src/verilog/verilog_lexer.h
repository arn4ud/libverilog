#ifndef LIBVERILOG_VERILOG_LEXER_H_
#define LIBVERILOG_VERILOG_LEXER_H_

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "verilog_parser.h"

namespace verilog {

class VerilogLexer : public yyFlexLexer {
public:
    VerilogLexer() = default;
    ~VerilogLexer() override = default;

    // get rid of override virtual function warning
    // using FlexLexer::yylex;

    int yylex(verilog::VerilogParser::semantic_type* const lval);
};

}  // namespace verilog

#endif  /* LIBVERILOG_VERILOG_LEXER_H_ */

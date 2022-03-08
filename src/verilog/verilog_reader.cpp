#include "verilog_reader.h"

#include "verilog_lexer.h"
#include "verilog_parser.h"

namespace verilog {

VerilogReader::VerilogReader()
    : _lexer(new VerilogLexer())
    , _parser(new VerilogParser(*_lexer, this)) {}

void VerilogReader::read(const std::filesystem::path& p){
  _parser->parse();
}

}  // namespace verilog

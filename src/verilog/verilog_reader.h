#ifndef LIBVERILOG_VERILOG_READER_
#define LIBVERILOG_VERILOG_READER_

#include <string>
#include <filesystem>

namespace verilog {

class VerilogLexer;
class VerilogParser;

class VerilogReader {
public:
    VerilogReader();
    virtual ~VerilogReader() = default;

    void read(const std::filesystem::path&); 

  private:
    VerilogLexer* _lexer;
    VerilogParser* _parser;
};

}  // namespace verilog

#endif  /* LIBVERILOG_VERILOG_READER_ */

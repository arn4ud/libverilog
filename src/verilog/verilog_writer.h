#ifndef LIBVERILOG_VERILOG_WRITER_
#define LIBVERILOG_VERILOG_WRITER_

#include <ostream>

namespace verilog {

class VerilogWriter {
public:
    VerilogWriter(std::ostream& os) : os_(os) {}

private:
    std::ostream& os_;
};

}  // namespace verilog

#endif  /* LIBVERILOG_VERILOG_WRITER_ */

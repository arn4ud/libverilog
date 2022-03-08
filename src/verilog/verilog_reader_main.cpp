#include <verilog/verilog_reader.h>

class MyVerilogReader final : public verilog::VerilogReader {
public:
};

int main(int argc, char* argv[])
{
   MyVerilogReader reader;
   for (int arg = 1; arg < argc; ++arg) {
       reader.read(argv[arg]);
   }
   return 0;
}

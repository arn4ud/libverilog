/*
 * Copyright 2019 The libverilog Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <fstream>
#include <iostream>

#include "verilog_lexer.h"
#include "verilog_parser.h"

class MyVerilogReader final : public verilog::VerilogReader {
public:
};

int main(int argc, char* argv[]) {
    MyVerilogReader reader;
    verilog::VerilogLexer lexer;
    verilog::VerilogParser parser(lexer, reader);

    parser.set_debug_level(1);
    for (int arg = 1; arg < argc; ++arg) {
        std::ifstream ifs(argv[arg]);
        if (!ifs) {
            std::cerr << argv[arg] << ": no such file\n";
            continue;
        }
        lexer.switch_streams(&ifs, nullptr);
        std::cout << "reading " << argv[arg] << '\n';
        parser.parse();
    }
    return 0;
}

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

#include "verilog_reader.h"

#include <fstream>

#include "verilog_lexer.h"
#include "verilog_parser.h"

namespace verilog {

VerilogReader::VerilogReader()
    : lexer_(new VerilogLexer())
    , parser_(new VerilogParser(*lexer_, *this)) {}

void VerilogReader::read(const std::filesystem::path& p){
    std::ifstream ifs(p);
    if (!ifs) {
        std::cerr << p << ": no such file\n";
    }
    lexer_->switch_streams(&ifs, nullptr);
    parser_->parse();
}

}  // namespace verilog

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

#ifndef LIBVERILOG_VERILOG_READER_
#define LIBVERILOG_VERILOG_READER_

#include <filesystem>
#include <optional>
#include <string>
#include <vector>

namespace verilog {

class VerilogLexer;
class VerilogParser;

class VerilogReader {
public:
    VerilogReader();
    virtual ~VerilogReader() = default;

    void read(const std::filesystem::path&); 

    virtual void visitModule(std::string&& moduleName) {} 

  private:
    VerilogLexer* _lexer;
    VerilogParser* _parser;
};

}  // namespace verilog

#endif  /* LIBVERILOG_VERILOG_READER_ */

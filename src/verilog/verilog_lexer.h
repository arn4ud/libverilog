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

    VerilogParser::symbol_type get_token();
};

}  // namespace verilog

#endif  /* LIBVERILOG_VERILOG_LEXER_H_ */

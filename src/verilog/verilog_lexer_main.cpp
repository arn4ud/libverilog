/*
 * Copyright (c) 2022 Arnaud Caron <arn4ud@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <fstream>
#include <iostream>
#include <verilog/verilog_lexer.h>

int main(int argc, char* argv[])
{
    verilog::VerilogLexer lexer;
    for (int arg = 1; arg < argc; ++arg) {
        std::ifstream ifs(argv[arg]);
        lexer.switch_streams(ifs, std::cout);

        int t;
        verilog::VerilogParser::semantic_type yylval;
        while ((t = lexer.yylex(&yylval)) != 0) {
            std::cout
                << "lineno: " << lexer.lineno() << " token: " << t
                << " text[" << lexer.YYLeng() << "]: " << lexer.YYText()
                << std::endl;
        }
        return 0;
    }
    return 0;
}

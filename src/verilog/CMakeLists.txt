add_library(verilog STATIC "")

target_include_directories(
  verilog
   PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
   PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
   PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR})

FLEX_TARGET(
  verilog_lexer
    ${CMAKE_CURRENT_SOURCE_DIR}/verilog_lexer.lpp
    ${CMAKE_CURRENT_BINARY_DIR}/verilog_lexer.cpp)
BISON_TARGET(
  verilog_parser
    ${CMAKE_CURRENT_SOURCE_DIR}/verilog_parser.ypp
    ${CMAKE_CURRENT_BINARY_DIR}/verilog_parser.cpp
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/verilog_parser.h)
ADD_FLEX_BISON_DEPENDENCY(verilog_lexer verilog_parser)

target_sources(
  verilog
   INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/verilog_reader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/verilog_writer.h
   PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/verilog_lexer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/verilog_lexer.h
    ${CMAKE_CURRENT_BINARY_DIR}/verilog_parser.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/verilog_parser.h
    ${CMAKE_CURRENT_SOURCE_DIR}/verilog_reader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/verilog_writer.cpp)

install(
  TARGETS verilog
    ARCHIVE
      DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER
      DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/verilog)

add_executable(verilog_reader_main verilog_reader_main.cpp)
target_link_libraries(verilog_reader_main verilog)

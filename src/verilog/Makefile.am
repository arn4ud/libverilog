AM_CPPFLAGS = -I$(srcdir)/.. -I$(builddir)/..

lib_LTLIBRARIES = libverilog.la

libverilog_ladir = $(includedir)/cdr
libverilog_la_HEADERS = \
	verilog_reader.h \
	verilog_writer.h

libverilog_la_SOURCES = \
	$(libverilog_la_HEADERS) \
        verilog_lexer.h \
        verilog_lexer.lpp \
	verilog_parser.ypp \
	verilog_reader.cpp \
	verilog_writer.cpp

# Build these files before anything else.
BUILT_SOURCES = \
	verilog_lexer.cpp \
	verilog_parser.cpp 
	verilog_parser.h
CLEANFILES = $(BUILT_SOURCES)

noinst_PROGRAMS = verilog_reader_main

verilog_reader_main_SOURCES = verilog_reader_main.cpp
verilog_reader_main_LDADD = libverilog.la

verilog_lexer.cpp: verilog_lexer.lpp
	$(FLEX) --outfile=verilog_lexer.cpp $<

verilog_parser.cpp verilog_parser.h: verilog_parser.ypp
	$(BISON) --output=verilog_parser.cpp --defines=verilog_parser.h $<

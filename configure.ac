dnl Process this file with autoconf to produce a configure script

AC_INIT(libverilog, 1.0)
AM_INIT_AUTOMAKE([-Wall -Werror foreign no-define subdir-objects serial-tests])

AM_SILENT_RULES([yes])
AC_CONFIG_MACRO_DIR([m4])

AX_CODE_COVERAGE()
AM_COND_IF([CODE_COVERAGE_ENABLED], [CFLAGS="$CODE_COVERAGE_CFLAGS"])
AM_COND_IF([CODE_COVERAGE_ENABLED], [CXXFLAGS="$CODE_COVERAGE_CFLAGS"])
AM_COND_IF([CODE_COVERAGE_ENABLED], [LDFLAGS="$CODE_COVERAGE_LDFLAGS"])

AM_PROG_AR
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_LIBTOOL
PKG_PROG_PKG_CONFIG

AC_PROG_LEX
AC_PATH_PROG([FLEX], [flex])
AC_PROG_YACC
AC_PATH_PROG([BISON], [bison])

AX_CXX_COMPILE_STDCXX_17([noext],[mandatory])

AC_OUTPUT([
Makefile
libverilog.pc
src/Makefile
src/verilog/Makefile])

dnl End of file

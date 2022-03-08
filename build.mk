SHELL = /bin/sh

thisdir = $(shell pwd)

# Generic Rules
# --------------------------------------------------

all: cmake-debug-all cmake-release-all cmake-coverage-all autotools-debug-all autotools-release-all autotools-coverage-all
check: cmake-debug-check check-release cmake-coverage-check autotools-debug-check check-release autotools-coverage-check
install: cmake-debug-install cmake-release-install cmake-coverage-install autotools-debug-install autotools-release-install autotools-coverage-install

# End of file

# CMake debug build
# --------------------------------------------------

cmake-debug-all: build/cmake-debug/Makefile
	$(MAKE) -C build/cmake-debug all

cmake-debug-check: cmake-debug-all
	$(MAKE) -C build/cmake-debug test

cmake-debug-install: cmake-debug-all
	$(MAKE) -C build/cmake-debug install

build/cmake-debug/Makefile:
	mkdir -p $(@D)
	cd $(@D) && cmake \
	    -DCMAKE_BUILD_TYPE=Debug \
	    -DCMAKE_INSTALL_PREFIX:PATH=$(thisdir)/build/cmake-debug ../..

.PHONY: cmake-debug-all cmake-debug-check cmake-debug-install

# CMake release build
# --------------------------------------------------

cmake-release-all: build/cmake-release/src/Makefile
	$(MAKE) -C build/cmake-release/src

check-release: cmake-release-all
	$(MAKE) -C build/cmake-release/src test

cmake-release-install: cmake-release-all
	$(MAKE) -C build/cmake-release/src install

build/cmake-release/src/Makefile:
	mkdir -p $(@D)
	cd $(@D) && cmake \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_INSTALL_PREFIX:PATH=$(thisdir)/build/cmake-release ../../..

.PHONY: cmake-release-all check-release cmake-release-install

# CMake coverage build
# --------------------------------------------------

cmake-coverage-all: build/cmake-coverage/src/Makefile
	$(MAKE) -C build/cmake-coverage/src

cmake-coverage-check: cmake-coverage-all
	$(MAKE) -C build/cmake-coverage/src test

cmake-coverage-install: cmake-coverage-all
	$(MAKE) -C build/cmake-coverage/src install

build/cmake-coverage/src/Makefile:
	mkdir -p $(@D)
	cd $(@D) && cmake \
		-DWITH_COVERAGE=YES \
		-DCMAKE_BUILD_TYPE=Debug \
		-DCMAKE_INSTALL_PREFIX:PATH=$(thisdir)/build/cmake-coverage ../../..

.PHONY: cmake-coverage-all cmake-coverage-check cmake-coverage-install

cmake-coverage-check-report: check-coverage
	cd ./build/cmake-coverage/src/CMakeFiles/verilogparser.dir/ ; \
	gcov -abcf *.o  ; \
	lcov --directory . -c -o cov.info -t "verilogparser" ; \
	genhtml -o ../../../../coverage-report -t "verilogparser" --num-spaces 4 cov.info
	@echo "Coverage report available in:"
	@echo "./build/cmake-coverage-report/index.html"

# Autotools debug build
# --------------------------------------------------

autotools-debug-all: build/autotools-debug/Makefile
	$(MAKE) -C build/autotools-debug all

autotools-debug-check: autotools-debug-all
	$(MAKE) -C build/autotools-debug test

autotools-debug-install: autotools-debug-all
	$(MAKE) -C build/autotools-debug install

build/autotools-debug/Makefile:
	mkdir -p $(@D)
	cd $(@D) && ../../configure \
	    --prefix=$(thisdir)/build/autotools-debug

.PHONY: cmake-debug-all cmake-debug-check cmake-debug-install

# Autotools release build
# --------------------------------------------------

autotools-release-all: build/autotools-release/Makefile
	$(MAKE) -C build/autotools-release all

autotools-release-check: autotools-release-all
	$(MAKE) -C build/autotools-release test

autotools-release-install: autotools-release-all
	$(MAKE) -C build/autotools-release install

build/autotools-release/Makefile:
	mkdir -p $(@D)
	cd $(@D) && ../../configure \
	    --prefix=$(thisdir)/build/autotools-release

.PHONY: cmake-release-all cmake-release-check cmake-release-install

# Autotools coverage build
# --------------------------------------------------

autotools-coverage-all: build/autotools-coverage/Makefile
	$(MAKE) -C build/autotools-coverage all

autotools-coverage-check: autotools-coverage-all
	$(MAKE) -C build/autotools-coverage test

autotools-coverage-install: autotools-coverage-all
	$(MAKE) -C build/autotools-coverage install

build/autotools-coverage/Makefile:
	mkdir -p $(@D)
	cd $(@D) && ../../configure \
	    --enable-code-coverage \
	    --prefix=$(thisdir)/build/autotools-coverage

.PHONY: cmake-coverage-all cmake-coverage-check cmake-coverage-install


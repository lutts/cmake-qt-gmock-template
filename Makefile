all: build

build: FORCE
	make -C build
	cp build/compile_commands.json ./

prepare:
	-mkdir build
	cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

cpplint: FORCE
	make -C build cpplint

cpplint-%:
	ENV_CPPLINT_ROOT=$* make -C build cpplint

test: build FORCE
	cd build && ctest --output-on-failure

test-%: build
	cd build && ctest --output-on-failure -R $*

list-test: FORCE
	cd build && ctest -N

Makefile:;

%:: FORCE
	make -C build $@
#	cp build/compile_commands.json ./

FORCE:

.PHONY: FORCE all cpplint

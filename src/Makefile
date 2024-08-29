.PHONY: all calc
SHELL = /bin/sh
FLAGS :=-std=c++17 -Wextra -Wall -Werror

TARGET = Calculator_v2.0
OUTNAME = smart_calc_qt

SOURCES_TEST := $(wildcard tests_s21/*.cpp) model/s21_smartcalc.cpp
LGFLAGS := -lgtest -lgtest_main

CC=g++


all: install
	open ../build/Calculator_v2.0.app

run:
	open ../build/Calculator_v2.0.app

install:       
	echo "Installation of $(TARGET).app:"
	mkdir -p ../build
	cd smart_calc_qt/ && qmake && make && make clean && rm -rf Makefile && mv smart_calc_qt.app ../../build/$(TARGET).app
	echo "Installation completed! You can find app in the ../build/ folder!"

uninstall:
	rm -rf ../build
	echo "Uninstall completed!"
	
dist: install
	mkdir -p ../dist
	cp -R ../build/$(TARGET).app ../dist
	cp -R . ../dist/src
	cd ../dist && tar cvzf $(TARGET).tgz *
	cd ../dist && rm -rf $(TARGET).app
	rm -rf ../dist/src
	echo "Archive creation completed successfully!"	

dvi: clean
	@doxygen Doxyfile
	open doxygen/html/index.html

tests: clean
	g++  $(SOURCES_TEST) --coverage $(FLAGS) $(LGFLAGS) -o test -L.
	./test

gcov_report: tests
	gcov -f *.gcda
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info 
	open report/index.html

style:
	clang-format -style=google -i */*.cpp */*.h

clean:
	rm -rf *.o *.info report $(TESTS) lexeme_parser *.gcda *.gcno *.gcov coverage.info coverage_html doxygen valgrind.out build* ../build test

open: install
	open $(APP)

cleanall:
	rm -rf *.o *.info doxygen ../build/Calculator_v1.0.app *.a smart_calc_qt/smart_calc_qt.app report a.out $(TESTS) lexeme_parser *.gcda *.gcno coverage.info coverage_html doxygen valgrind.out build*

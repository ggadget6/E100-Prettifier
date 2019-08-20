# Makefile
# Build rules for EECS 280 lab08

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = --std=c++11 -Wall -Werror -pedantic -g

# To call the program, type "make pretty infilename=(filename here) outfilename=(filename here)"
pretty: Prettifier.exe
	./Prettifier.exe $(infilename) $(outfilename)

Prettifier.exe: main.cpp Prettifier.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rvf *.exe *.out.txt *.out.ppm *.dSYM *.stackdump

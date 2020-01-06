# Makefile

# the C++ compiler
CXX = g++
CXXVERSION = $(shell g++ --version | grep ^g++ | sed 's/^.* //g')

CXXFLAGS = -O0 -g3 -std=c++14

All: all
all: main main

main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

deepclean:
	rm -f *~ *.o *.gch main *.exe *.stackdump main

clean:
	-rm -f *~ *.o *.gch *.stackdump
CXX=clang++
CXXFLAGS= -std=c++1z -ggdb

all: part1 part2

part1: part1.cpp
	$(CXX) -o part1 $(CXXFLAGS) part1.cpp

part2: part2.cpp
	$(CXX) -o part2 $(CXXFLAGS) part2.cpp

run: part1 part2	
	./part1 < input
	./part2 < input

sample: part1 part2	
	./part1 < sample
	./part2 < sample

clean:
	rm part1 part2

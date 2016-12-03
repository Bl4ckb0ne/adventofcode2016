CXX=clang++
CXXFLAGS= -std=c++1z

all: one two

one: one.cpp
	$(CXX) -o one $(CXXFLAGS) one.cpp 	
	./one < code

two: two.cpp
	$(CXX) -o two $(CXXFLAGS) two.cpp 
	./two < code	

clean:
	rm one two

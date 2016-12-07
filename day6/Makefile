CXX=clang++
CXXFLAGS= -std=c++1z

EXE=day6

all: run

$(EXE): main.cpp
	$(CXX) -o $(EXE) $(CXXFLAGS) main.cpp 	

run: $(EXE)	
	./$(EXE) < input

sample: $(EXE)	
	./$(EXE) < sample

clean:
	rm $(EXE)

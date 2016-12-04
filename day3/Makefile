CXX=clang++
CXXFLAGS= -std=c++1z

EXE=day3

all: $(EXE)

$(EXE): main.cpp
	$(CXX) -o $(EXE) $(CXXFLAGS) main.cpp 	

run: $(EXE)	
	./$(EXE) < input

sample: $(EXE)	
	./$(EXE) < sample

clean:
	rm $(EXE)

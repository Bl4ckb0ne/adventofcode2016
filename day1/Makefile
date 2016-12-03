CXX=clang++
CXXFLAGS= -std=c++1z

EXE=day1

all: $(EXE)

$(EXE): main.cpp
	$(CXX) -o $(EXE) $(CXXFLAGS) main.cpp 	

one: $(EXE)	
	./$(EXE) 0 0 < part_one

sample: $(EXE)	
	./$(EXE) < sample

clean:
	rm $(EXE)

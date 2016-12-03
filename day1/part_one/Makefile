CXX=clang++
CXXFLAGS= -std=c++1z

EXE=day1

all: $(EXE)

$(EXE): main.cpp
	$(CXX) -o $(EXE) $(CXXFLAGS) main.cpp 	

run: $(EXE)	
	./$(EXE) < data

sample: $(EXE)	
	./$(EXE) < sample

clean:
	rm $(EXE)

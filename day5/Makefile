CXX=clang++
CXXFLAGS= -std=c++1z

EXE=day5

all: $(EXE)
	./$(EXE)

$(EXE): main.cpp md5.cpp md5.h
	$(CXX) -o $(EXE) $(CXXFLAGS) main.cpp md5.cpp

clean:
	rm $(EXE)


CXX= g++
CXXFLAGS= -O3

SRCS= dat_file_input.cpp bin_file_input.cpp gz_file_input.cpp
OBJS= $(patsubst %.cpp, %.o, $(SRCS))
LIB= libdatainput.a
EXE= example

all: $(EXE)
lib: $(LIB)

$(LIB): $(OBJS)
	ar rs $(LIB) $(OBJS)

$(EXE): $(LIB) example.cpp file_input.h
	$(CXX) -o $(EXE) $(CXXFLAGS) example.cpp -L. -ldatainput

$(OBJS): file_input.h

$(OBJS): %.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@
	
clean:
	rm -f *.o
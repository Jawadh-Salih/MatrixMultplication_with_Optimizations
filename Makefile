appname := matrix_multiply

CXX := g++

CXXFLAGS := -fopenmp



srcfiles := $(shell find . -name "main.cpp")
objects  := $(patsubst %.C, %.o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CXX) -c -O3 -msse3 -fopenmp optimized.cpp

	$(CXX) $(CXXFLAGS) -O3 $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS) optimized.o




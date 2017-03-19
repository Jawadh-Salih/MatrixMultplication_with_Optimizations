appname := concurrent_lab3

CXX := g++

CXXFLAGS := -fopenmp



srcfiles := $(shell find . -name "main.cpp")
objects  := $(patsubst %.C, %.o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CXX) -c -O3 -fopenmp optimized.cpp

	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS) optimized.o




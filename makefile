CXX = g++
CXXFLAGS = -Wall -std=c++11

all: testbst

testbst: intbst.cpp testbst.cpp
	$(CXX) $(CXXFLAGS) intbst.cpp testbst.cpp -o testbst

clean:
	rm -f testbst
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

main: *.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
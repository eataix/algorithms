CXX=clang++
CXXFLAGS=-std=c++1y -Wall -Wextra

all:
	@echo "Don't Panic."

%.debug: %.cpp
	$(CXX) $(CXXFLAGS) -O2 -g -o $@ $<

%.run: %.cpp
	$(CXX) $(CXXFLAGS) -O3 -o $@ $<

.PHONY: clean

clean:
	rm -f *.debug
	rm -f *.run

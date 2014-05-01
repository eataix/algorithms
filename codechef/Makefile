CXX=clang++
CXXFLAGS=-O2 -g -std=c++11 -Wall -Wextra

all:
	@echo "Don't Panic."

%.out: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY: clean

clean:
	rm -f *.out

CXX=clang++
CXXFLAGS=-O2 -g -std=c++98 -Wall -Wextra -pedantic

all:
	@echo "Don't Panic."

%.out: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY: clean

clean:
	rm -f *.out

CXX=clang++
CXXFLAGS=-g -Wall -Wextra -O0 -std=c++2a -pedantic -ggdb -D DEBUG

format:
	ls *.cpp | parallel clang-format -i
	yapf -i *.py

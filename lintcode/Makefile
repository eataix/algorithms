CXX=clang++
CXXFLAGS=-g -Wall -Wextra -O3 -std=c++2a -pedantic -D_FORTIFY_SOURCE=2 -D_GLIBCXX_ASSERTIONS -fasynchronous-unwind-tables -fexceptions -fstack-protector -fstack-protector-strong -g -Werror=format-security -Werror=implicit-function-declaration -D DEBUG

format:
	ls *.cpp | parallel clang-format -i

.PHONY:build
build:
	c++ --version
	c++ -std=c++14 -Wall -O0 -g -o main ./main.cpp
	./main

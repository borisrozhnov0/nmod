.PHONY: test
default: test

test: test.cc
	g++ -I./include $< -Wall -std=c++17 -o $@
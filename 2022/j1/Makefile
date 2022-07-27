.PHONY: all test clean

all: test

test: obj/j1_c obj/j1_cpp
	./test_all.sh

obj/j1_c: j1.c
	${CC} -o $@ $?

obj/j1_cpp: j1.cpp
	g++ -o $@ $?

clean:
	rm -f obj/*

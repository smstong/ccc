.PHONY: all test clean

all: test

test: obj/j3_c
	./test_all.sh

obj/j3_c: j3.c
	${CC} -o $@ $?

clean:
	rm -f obj/*

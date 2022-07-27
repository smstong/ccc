.PHONY: all test clean

all: test

test: obj/j5_c
	./test_all.sh

obj/j5_c: j5.c
	${CC} -o $@ $?

clean:
	rm -f obj/*

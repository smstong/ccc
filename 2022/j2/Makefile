.PHONY: all test clean

all: test

test: obj/j2_c
	./test_all.sh

obj/j2_c: j2.c
	${CC} -o $@ $?

clean:
	rm -f obj/*

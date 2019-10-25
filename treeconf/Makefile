CFLAGS = -g -Wall

all: config.h config.c cfg_test.c string.h
	gcc ${CFLAGS} -o test cfg_test.c config.c

clean:
	rm -f test test.exe


WFLAGS= -Wall -Wextra -Wpedantic
CFLAGS= $(WFLAGS)
CPPFLAGS= -std=c++11 $(WFLAGS)
CC=gcc

.PHONY: clean


sbtex: main.o log.o cmdParser.o 
	$(CC) -o $@ $^ $(CFLAGS)

dev: CFLAGS+=-g
dev: sbtex

clean:
	rm -f *.o sbtex

cmdParser.o: cmdParser.hpp defaults.hpp

%.o: %.cpp
	$(CC) -c $< $(CPPFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

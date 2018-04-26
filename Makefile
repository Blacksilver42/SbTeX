INSTALL=/etc/SbTeX/

WFLAGS= -Wall -Wextra -Wpedantic
CFLAGS= $(WFLAGS) '-DINSTALL="$(INSTALL)"'
CPPFLAGS= -std=c++11 $(CFLAGS)
CC=gcc

.PHONY: clean


sbtex: main.o log.o cmdParser.o | $(INSTALL)
	$(CC) -o $@ $^ $(CFLAGS)

$(INSTALL): fonts/
	mkdir -p $@
	cp -r fonts/ $@

dev: CFLAGS+=-g
dev: sbtex

clean:
	rm -f *.o sbtex

cmdParser.o: cmdParser.hpp defaults.hpp

%.o: %.cpp
	$(CC) -c $< $(CPPFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

CFLAGS= -std=c++11
.PHONY: clean


sbtex: main.o cmdParser.o logger.o logf.o
	g++ $(CFLAGS) -o $@ $^

dev: CFLAGS+=-g
dev: sbtex

clean:
	rm -f *.o sbtex

cmdParser.o: cmdParser.hpp defaults.hpp

%.o: %.cpp
	g++ $(CFLAGS) -c $<


.PHONY: clean


sbtex: main.o cmdParser.o logger.o
	g++ $(CFLAGS) -o $@ $^

dev: CFLAGS+=-g
dev: sbtex

clean:
	rm *.o sbtex

cmdParser.o: cmdParser.hpp defaults.hpp

%.o: %.cpp
	g++ $(CFLAGS) -c $<


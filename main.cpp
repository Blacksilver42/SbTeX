#include "logger.hpp"
#include <stdlib.h>
#include "cmdParser.hpp"
Logger logger(ERROR);
int main (int argc, char* argv[]){
	Info info;
	int r = getInfo(argc, argv, info);
	if(r != 0){
		return r;
	}
	// phew, that worked.
	return 0;
}

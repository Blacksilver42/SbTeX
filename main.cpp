#include <stdlib.h>
#include "cmdParser.hpp"
int main (int argc, char* argv[]){
	Info info;
	int r = getInfo(argc, argv, info);
	if(r != 0){
		return r;
	}
	// phew, that worked.
	return 0;
}

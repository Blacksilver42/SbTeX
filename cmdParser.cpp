#include "cmdParser.hpp"
#include "defaults.hpp"
#include "log.h"

int getRandomNumber(){
	return 4; // Chosen by a fiar dice roll.
              // guaranteed to be random
}

int getInfo(int argc, char* argv[], Info &info){
	
	info.arg0 = argv[0];
	
	// Parse for -o <OUTFILE> and -f <FONT>
	int i;
	info.outfile = stdout;
	info.outfile_name = "stdout";
	info.font = DEFAULT_FONT;
	info.input = NULL;
	
	for(i=0;i<argc;i++){
		if(strcmp(argv[i],"-o") == 0){
			info.outfile = fopen(argv[i+1], "w");
			info.outfile_name = argv[i+1];
			
			if(info.outfile == NULL){
				error(1, errno, "%s", info.outfile_name);
			}
		}
		if((strcmp(argv[i],"-f") == 0) || strcmp(argv[i],"--font") == 0){
			info.font = argv[i+1];
		}
		
		if(strcmp(argv[i],"-i") == 0){
			info.input = argv[i+1];
		}
		
		if(strcmp(argv[i], "-v") == 0){
			loglevel+=1;
		}
		
		if(strcmp(argv[i], "-V") == 0){
			loglevel+=2;
		}
	}
	
	sprintf(info.fontpath, "%sfonts/%s/",INSTALL, info.font);
	
	if(info.input == NULL){
		error(1, EINVAL, "\b\b");
	}
	
	sbtex_log(1, "Output:\t%s\n", info.outfile_name);
	sbtex_log(1, "Font:\t%s\n", info.fontpath);
	sbtex_log(1, "Input:\t'%s'\n", info.input);
	return 0;
}

// vim: ts=4

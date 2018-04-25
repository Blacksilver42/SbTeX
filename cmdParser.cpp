#include "cmdParser.hpp"
#include "defaults.hpp"
#include "log.h"



int getInfo(int argc, char* argv[], Info &info){
	
	info.arg0 = argv[0];
	
	// Parse for -o <OUTFILE>
	int i;
	info.outfile = stdout;
	info.outfile_name = "stdout";
	for(i=0;i<argc;i++){
		if(strcmp(argv[i],"-o") == 0){
			info.outfile = fopen(argv[i+1], "w");
			info.outfile_name = argv[i+1];
			
			if(info.outfile == NULL){
				fprintf(stderr, "%s: %s: %s\n", info.arg0, info.outfile_name, strerror(errno));
				return 1;
			}
		}
	}
	
	// Parse for -f <FONT>
	info.font = DEFAULT_FONT;
	for(i=0;i<argc;i++){
		if((strcmp(argv[i],"-f") == 0) || strcmp(argv[i],"--font") == 0){
			info.font = argv[i+1];
			break;
		}
	}
	sprintf(info.fontpath, "fonts/%s/",info.font);
	
	// Parse for -i <INPUT>
	info.input = NULL;
	
	for(i=0;i<argc;i++){
		if(strcmp(argv[i],"-i") == 0){
			info.input = argv[i+1];
		}
	}
	if(info.input == NULL){
		errno = EINVAL;
		fprintf(stderr, "%s: %s\n", info.arg0, strerror(errno));
		return 1;
		// TODO: Read from stdin 
	}
	
	sbtex_log(1, "Output:\t%s\n", info.outfile_name);
	sbtex_log(1, "Font:\t%s\n", info.fontpath);
	sbtex_log(1, "Input:\t'%s'\n", info.input);
	return 0;
}

// vim: ts=4

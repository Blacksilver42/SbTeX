#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define VERBOSE_PARSER

enum Verbosity{
	DEBUG,
	ERROR,
	QUIET,
};

struct Info{
	char * arg0; // name of the program, i.e., argv[0]
	char * input;
	const char * font;
	char fontpath[256];
	FILE * outfile;
	Verbosity verbosity;
	const char * outfile_name;
};

int getInfo(int argc, char* argv[], Info *info);

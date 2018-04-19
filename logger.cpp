#include <stdio.h>

#include "logger.hpp"
#include "cmdParser.hpp"

Logger::Logger(Verbosity verbosity){
	m_verbosity = verbosity;
}

void Logger::log(Verbosity level, const char* location, const char* what){
	if (level >= m_verbosity){
		switch (level){
			case DEBUG: fprintf(stdout, "[DEBUG] @%s: %s\n", location, what); break;
			case ERROR: fprintf(stderr, "[ERROR] @%s: %s\n", location, what); break;
			default: ; //be quiet
		}
	}
}

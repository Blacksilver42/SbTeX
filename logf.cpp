#include "logger.hpp"
template<typename... Args>
void Logger::logf(Verbosity level, const char* location, const char* format, Args... args){
	if (level >= m_verbosity){
		switch (level){
			case DEBUG: fprintf(stdout, "[DEBUG] @%s: ", location); fprintf(stdout, format, (args)...); fprintf(stdout, "\n"); break;
			case ERROR: fprintf(stderr, "[ERROR] @%s: ", location); fprintf(stderr, format, (args)...); fprintf(stderr, "\n"); break;
			default: ; //be quiet
		}
	}
}

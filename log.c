#include "log.h"
#include <stdarg.h>
#include <stdio.h>

int loglevel = 1;

int sbtex_log(int level, const char * format, ...){
	int r = 0;
#ifndef SBTEX_STFU
	//printf("loglevel=%d, level=%d\n",loglevel, level);
    if(level <= loglevel){
        va_list ap;
        va_start(ap, format);
        r = vfprintf(stderr, format, ap);
        va_end(ap);
    }
#endif
	return r;
}

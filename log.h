// Prevent c++ name mangling
#if defined (__cplusplus)
extern "C" {
#endif

#define LQUIET 0
#define LINFO 1  // -v
#define LDEBUG 2 // -V

extern int loglevel;
int sbtex_log(int level, const char * format, ...);

#if defined (__cplusplus)
}
#endif

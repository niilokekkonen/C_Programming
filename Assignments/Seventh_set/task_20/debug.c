#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
// Static debug level
static int Sdebug_level = 0;

// Sets the static debug level visible in debug.c
void set_debug_level(int debug_level) 
{
	Sdebug_level = debug_level;
}
// if debug_level <= than static debug_lvl prints stderr message, and returns 1 for success
// else prints nothing, and returns zero
int dprintf(int debug_level, const char *fmt, ...) 
{
    if(debug_level <= Sdebug_level) 
    {
        va_list args;
        va_start(args, fmt);
        fprintf(stderr, "[DBG%d]\t", debug_level);
        vfprintf(stderr, fmt, args);
        va_end(args);
        return 1;
    }
    else 
    {
	    return 0;
    }
	
}

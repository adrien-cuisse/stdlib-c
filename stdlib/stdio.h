
/**
 * Global stdlib library
 * Fetches the appropriate system-specific header
 */




#ifndef GLOBAL_STDIO_HEADER
#define GLOBAL_STDIO_HEADER




/**
 * Fetching the appropriate system-specific header
 */
#if __linux__
#	if __x86_64__
#		include "System/linux/x64/stdio/stdio.h"
#	elif __i386__
#		include "32 bits not implemented yet"
#	else
#		error "unknown linux"
#	endif 
#elif _WIN64
#	error "windows x64 not implemented yet"
#elif _WIN32
#	error "windows x86 not implemented yet"
#else
#	error "Unknown system"
#endif



#endif /* GLOBAL_STDIO_HEADER */

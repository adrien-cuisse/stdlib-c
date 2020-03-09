
/**
 * Global stdlib library
 * Fetches the appropriate system-specific header
 */




#ifndef GLOBAL_STDLIB_HEADER
#define GLOBAL_STDLIB_HEADER




/**
 * Fetching the appropriate system-specific header
 */
#if __linux__
#	if __x86_64__
#		include "System/linux/x64/stdlib/stdlib.h"
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




/**
 * Invalid address
 */
#define NULL ((void *) 0)


/**
 * Default error status
 */
#define EXIT_FAILURE -1


/**
 * Default OK status
 */
#define EXIT_SUCCESS 0




#include "stdlib/abs.h"
#include "stdlib/atoi.h"
#include "stdlib/atol.h"
#include "stdlib/labs.h"




#endif /* GLOBAL_STDLIB_HEADER */

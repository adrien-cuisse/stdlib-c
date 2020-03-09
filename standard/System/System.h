
/**
 * Global system header
 * Fetches the appropriate specific system header
 */




#ifndef SYSTEM_HEADER
#define SYSTEM_HEADER




/**
 * Include appropriate system call numbers
 */
#if __linux__
#	if __x86_64__
#		include "linux/x64/system/system.h"
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




#endif /* SYSTEM_HEADER */

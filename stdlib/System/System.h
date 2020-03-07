
#ifndef SYSTEM_HEADER
#define SYSTEM_HEADER




/**
 * Include appropriate system call numbers
 */
#if __linux__
#	if __x86_64__
#		include "asm/linux/x64/codes.h"
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
 * Executes the given system call
 * Writen in assembly, head to the appropriate asm/ folder for code
 * Varadics will be stored in rdi, rsi, rdx, rcx, r8, r9, [stack]
 * 
 * @param id - the call number
 * 
 * @return - the result of the system call
 */
extern int __system_call(int id, ...);




/**
 * Exits the program with given status
 * 
 * @param status - the exit status, usually 0 if everthing went fine
 * 
 * @return [int] - the system call result
 **/
#define System_exit(status) __system_call(SYSTEM_CALL_CODE_EXIT, status)


/**
 * Writes to the given file descriptor
 *
 * @param fileDescriptor [int] - where to write
 * @param string [const char * const] - the string to write
 * @param count [unsigned char] - the number of bytes to write
 * 
 * @return [int] - the number of bytes writen
 */ 
#define System_write(fileDescriptor, string, count) __system_call(SYSTEM_CALL_CODE_WRITE, fileDescriptor, string, count)


/**
 * Writes to STDOUT
 * 
 * @param string [const char * const] - the string to write
 * @param count [unsigned int] - the number of bytes to write
 * 
 * @return [int] - the number ot bytes writen
 */
#define System_output(string, count) System_write(1, string, count)


/**
 * Writes to STDERR
 * 
 * @param string [const char * const] - the string to write
 * @param count [int] - the number of bytes to write
 * 
 * @return [int] - the number ot bytes writen
 */
#define System_outputError(string, count) System_write(2, string, count)




#endif /* SYSTEM_HEADER */

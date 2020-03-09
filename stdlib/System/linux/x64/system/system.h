
/**
 * Linux x64 system calls module
 */




#ifndef LINUX64_SYSTEM_HEADER
#define LINUX64_SYSTEM_HEADER




/**
 * System call numbers are required 
 */
#include "codes.h"




/**
 * Label located right after the data segment
 * Sent by the linker
 */
extern long _end;


/**
 * The address of the data segment's end
 */
long * breakpoint;




/**
 * Executes the given system call
 * Writen in assembly, head to the appropriate asm/ folder for code
 * Varadics will be stored in rdi, rsi, rdx, rcx, r8, r9, [stack]
 * 
 * @param id - the call number
 * 
 * @return - the result of the system call
 */
extern long __system_call(int id, ...);




#include "sbrk.h"
#include "exit.h"
#include "write.h"




#endif /* LINUX64_SYSTEM_HEADER */

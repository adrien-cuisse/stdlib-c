
#include "system.h"




/**
 * Allocates [increment] bytes on the heap
 * 
 * @param increment - how many bytes to allocate
 * 
 * @return - the new address for the data segment's end
 */
void * sbrk(unsigned long increment)
{
    extern long * breakpoint;

    if (! breakpoint) /* First call */
    {    
		breakpoint = (void *) __system_call(SYSTEM_CALL_CODE_BRK, 0);
    }
	
	return (void *) __system_call(SYSTEM_CALL_CODE_BRK, breakpoint + increment);
}

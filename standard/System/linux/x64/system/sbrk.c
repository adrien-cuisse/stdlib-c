
#include "brk.h"
#include "system.h"




void * sbrk(unsigned long increment)
{
    extern long * breakpoint;
	long * newBreakpoint;

	/* First call, init the heap */
    if (! breakpoint)
    {    
		breakpoint = (void *) __system_call(SYSTEM_CALL_CODE_BRK, 0);
    }
	
	newBreakpoint = (void *) __system_call(SYSTEM_CALL_CODE_BRK, breakpoint + increment);

	/* Error: couldn't change breakpoint */
	if (newBreakpoint == breakpoint)
	{
		return (void *) -1;
	}

	/* Store the new break point */
	brk(newBreakpoint);

	/* Previous reak point can now be used on the heap */
	return breakpoint;
}

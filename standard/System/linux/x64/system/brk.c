
#include "system.h"




int brk(void * location)
{
	extern long * breakpoint;
	long * newBreakpoint;

	newBreakpoint = (void *) __system_call(SYSTEM_CALL_CODE_BRK, location);

	if (newBreakpoint == breakpoint)
	{
		return -1;
	}

	return 0;
}


#ifndef BRK_HEADER
#define BRK_HEADER



/**
 * Sets the heap breakpoint to the given address
 * 
 * @param location - the address of the new breakpoint
 * 
 * @return - 0 on success, -1 on failure
 */
int brk(void * location);




#endif /* BRK_HEADER */


#ifndef BRK_HEADER
#define BRK_HEADER




/**
 * Allocates [increment] bytes on the heap
 * 
 * @param increment - how many bytes to allocate
 * 
 * @return - pointer to the newly allocated memory, or -1 on failure
 */
void * sbrk(unsigned long increment);




#endif /* BRK_HEADER */

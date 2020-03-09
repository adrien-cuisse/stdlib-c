
#ifndef BRK_HEADER
#define BRK_HEADER




/**
 * Increase the heap size by [increment] bytes
 * 
 * @param increment - how many bytes to add to the heap
 * 
 * @return - the new address of the data segment's end
 */
void * sbrk(unsigned long increment);




#endif /* BRK_HEADER */


#include "malloc.h"
#include "../system/sbrk.h"



void * malloc(unsigned long bytesCount)
{
	char * flagBlock; /* flags: used, virtual memory, etc */
	long * memoryBlock;

	if (! bytesCount)
	{
		return (void *) 0;
	}

	memoryBlock = sbrk(bytesCount + sizeof(* flagBlock));
	
	/* Allocation failed, return NULL */
	if ((void *) -1 == memoryBlock)
	{
		return (void *) 0;
	}

	/* Writting the header saying the block is currently used */
	flagBlock = (char *) memoryBlock;
	* flagBlock = 1; 

	/* Returning the block after the header */
	return ((char *) memoryBlock + 1); 
}

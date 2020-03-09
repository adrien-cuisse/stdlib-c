
#include "free.h"




void free(void * memoryBlock)
{
	char * header;

	header = ((char *) memoryBlock) - 1;
	* header = 0;

	/**
	 * TODO:
	 *   set new breakpoint if one full page at the end can be freed
	 */
}
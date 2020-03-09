
#include "strstr.h"




const char * strstr(const char * haystack, const char * needle)
{
	const char * match;
	const char * needleIterator;

	if (! (* needle))
	{
		return (void *) 0;
	}

	while (* haystack)
	{
		match = haystack;
		needleIterator = needle;

		while ((* needleIterator) == (* haystack)) 
		{
			haystack++;
			needleIterator++;
		}

		if ('\0' == (* needleIterator)) 
		{
			return match;
		}

		haystack++;
	}

	return (void *) 0;
}

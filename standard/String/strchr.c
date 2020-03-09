
#include "strchr.h"




const char * strchr(const char * string, char character)
{
	while (* string)
	{
		if ((* string) == character)
		{
			return string;
		}
		string++;
	}
	return (void *) 0;
}

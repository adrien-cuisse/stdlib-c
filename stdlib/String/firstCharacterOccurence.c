
#include "firstCharacterOccurence.h"




const char * String_firstCharacterOccurence(const char * string, char character)
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

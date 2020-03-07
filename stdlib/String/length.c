
#include "String.h"




unsigned int String_length(const char * string)
{
	int length;

	length = 0;
	while (* string++){
		length++;
	}
	
	return length;
}

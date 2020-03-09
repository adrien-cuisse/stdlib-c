
#include "strlen.h"




unsigned int strlen(const char * string)
{
	int length;

	length = 0;
	while (* string++){
		length++;
	}
	
	return length;
}

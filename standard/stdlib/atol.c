
#include "../Character/macros.h"
#include "atol.h"




long atol(const char * string)
{
	char previousCharacter = '\0';
	int value = 0;

	while (IS_NOT_DIGIT(* string))
	{
		previousCharacter = * string++;
	}

	while (IS_DIGIT(* string))
	{
		value *= 10;
		value += DIGIT_VALUE(* string);
		string++;
	}

	if ('-' == previousCharacter)
	{
		return -value;
	}

	return value;
}

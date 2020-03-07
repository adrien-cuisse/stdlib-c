
#include "stdlib/System/System.h"

#include "stdlib/String/length.h"
#include "stdlib/String/firstCharacterOccurence.h"
#include "stdlib/String/firstOccurence.h"

#define FALSE 0
#define TRUE 1


void assert(int expected, int computed)
{
	static int testId = 1;
	char * output = "Test failed, check error code\n";
	
	if (expected != computed)
	{
		System_outputError(output, String_length(output));
		/*System_exit(computed);*/
		System_exit(testId);
	}

	testId++;
}




void _start(int count, char ** vector)
{
	/*int length;*/


	char * digits = "01234567890";

	/* rdi = 60, ??? = 42 */
	/* 60 should be in rax, where's the 42 ? */
	
	/*length = String_toInteger("3");*/
	/*System_write(1, "123456789", length);
	System_write(1, "\n", 1);*/

	/*System_write(1, "Hello world!\n", 13);*/

	/* 1 - 2 */
	assert(10, String_length("0123456789"));
	assert(0, String_length(""));

	/* 3 - 6 */
	assert(TRUE, String_firstCharacterOccurence(digits, '0') == digits);
	assert(TRUE, String_firstCharacterOccurence(digits, '5') == digits + 5);
	assert(FALSE, String_firstCharacterOccurence(digits, 's') == digits);
	assert(TRUE, String_firstCharacterOccurence(digits, ' ') == (void *) 0);

	/* 7 - 14 */
	assert(TRUE, String_firstOccurence(digits, "") == (void *) 0);
	assert(TRUE, String_firstOccurence(digits, "ab") == (void *) 0);
	assert(TRUE, String_firstOccurence(digits, "12") == (digits + 1));
	assert(TRUE, String_firstOccurence(digits, "13") == (void *) 0);
	assert(TRUE, String_firstOccurence("", "") == (void *) 0);
	assert(TRUE, String_firstOccurence("", "s") == (void *) 0);
	assert(TRUE, String_firstOccurence(" ", "  ") == (void *) 0);
	assert(2, String_firstOccurence("ssSsssSSss", "S") - "ssSsssSSss"); /* thanks compiler, var declarations takes too much time */
	
	System_output("Tests passed\n", 13);
	
	System_exit(0);
}

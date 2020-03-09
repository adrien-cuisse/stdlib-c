

#include "standard/stdio.h"
#include "standard/stdlib.h"

#include "standard/String/String.h"
#include "standard/System/System.h"


#define FALSE 0
#define TRUE 1


void assert(int expected, int computed)
{
	static int testId = 1;
	char * output = "Test failed, check error code\n";
	
	if (expected != computed)
	{
		write(2, output, strlen(output));
		/*System_exit(computed);*/
		exit(testId);
	}

	testId++;
}


void printnbr(long number, const char * const alphabet, unsigned int base)
{
	if (number < 0)
	{
		write(1, "-", 1);
		printnbr(~ number, alphabet, base);
	}

	if (number >= base)
	{
		printnbr(number / base, alphabet, base);
	}
	
	write(1, & alphabet[number % base], 1);
}

void printptr(void * ptr)
{
	write(1, "0x", 2);
	printnbr((long) ptr, "0123456789abcdef", 16);
}

void donothing(void * ptr)
{
	if (ptr)
	{
		write(1, "", 0);
	}
	else
	{
		write(2, "", 0);
	}
}


void _start(int count, char ** vector)
{
	/*int length;*/


	char * digits = "01234567890";

	exit(atoi("-42"));
	printptr(sbrk(0));
	write(1, "\n", 1);
	
	printptr(sbrk(2));
	write(1, "\n", 1);

	/*void * temp;

	temp = sbrk(32);
		printptr(& _end);
		write(1, "\n", 1);
	printptr(temp);
	write(1, "\n", 1);
		printptr(& _end);
		write(1, "\n", 1);
	
	temp = sbrk(32);

		printptr(& _end);
		write(1, "\n", 1);
	printptr(temp);
	write(1, "\n", 1);
		printptr(& _end);
		write(1, "\n", 1);
	
	printptr(& _end);
	write(1, "\n", 1);*/

	exit(0);

	/* rdi = 60, ??? = 42 */
	/* 60 should be in rax, where's the 42 ? */
	
	/*length = String_toInteger("3");*/
	/*System_write(1, "123456789", length);
	System_write(1, "\n", 1);*/

	/*System_write(1, "Hello world!\n", 13);*/

	/* 1 - 2 */
	assert(10, strlen("0123456789"));
	assert(0, strlen(""));

	/* 3 - 6 */
	assert(TRUE, strchr(digits, '0') == digits);
	assert(TRUE, strchr(digits, '5') == digits + 5);
	assert(FALSE, strchr(digits, 's') == digits);
	assert(TRUE, strchr(digits, ' ') == (void *) 0);

	/* 7 - 14 */
	assert(TRUE, strstr(digits, "") == (void *) 0);
	assert(TRUE, strstr(digits, "ab") == (void *) 0);
	assert(TRUE, strstr(digits, "12") == (digits + 1));
	assert(TRUE, strstr(digits, "13") == (void *) 0);
	assert(TRUE, strstr("", "") == (void *) 0);
	assert(TRUE, strstr("", "s") == (void *) 0);
	assert(TRUE, strstr(" ", "  ") == (void *) 0);
	assert(2, strstr("ssSsssSSss", "S") - "ssSsssSSss"); /* thanks compiler, var declarations takes too much time */
	
	write(1, "Tests passed\n", 13);
	
	exit(0);
}

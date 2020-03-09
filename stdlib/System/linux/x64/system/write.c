
#include "system.h"




int write(int fileDescriptor, const char * const string, int count)
{
	return __system_call(SYSTEM_CALL_CODE_WRITE, fileDescriptor, string, count);
}

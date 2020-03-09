
#include "system.h"




int exit(int status)
{
	return __system_call(SYSTEM_CALL_CODE_EXIT, status);
}

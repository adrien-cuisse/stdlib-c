
#ifndef WRITE_HEADER
#define WRITE_HEADER




/**
 * Writes to the given file descriptor
 *
 * @param fileDescriptor - where to write
 * @param string - the string to write
 * @param count - the number of bytes to write
 * 
 * @return - the number of bytes writen
 */
int write(int fileDescriptor, const char * const string, int count);




#endif /* WRITE_HEADER */

#include "multithreading.h"

/**
* tprintf -  print out a given formatted string and the  calling thread ID
* @format: is string format
* Return: 0 on success
*/
int tprintf(char const *format, ...)
{
	va_list args;
	pthread_t thread;

	thread = pthread_self();
	setbuf(stdout, NULL);
	va_start(args, format);
	printf("[%lu] ", thread);
	vprintf(format, args);
	va_end(args);

	return (0);
}

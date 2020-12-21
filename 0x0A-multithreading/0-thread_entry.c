#include "multithreading.h"

/**
 * thread_entry - define an entry
 * @arg: are the args
 * Return: a void pointer
 */
void *thread_entry(void *arg)
{
	const char *string = (char *)arg;

	printf("%s\n", string);

	pthread_exit(NULL);
}

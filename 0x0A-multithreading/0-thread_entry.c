#include "multithreading.h"

void *thread_entry(void *arg)
{
	const char *string = (char *)arg;

	printf("%s\n", string);

	pthread_exit(NULL);
}

#include "multithreading.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

__attribute__((constructor)) void begin(void)
{
	pthread_mutex_init(&lock, NULL);
}

__attribute__((destructor)) void end(void)
{
	pthread_mutex_destroy(&lock);
}

/**
 * tprintf - print a format
 * @format: is the given format
 * Return: somenthing
 */
int tprintf(char const *format, ...)
{
	va_list args;
	pthread_t thread;

	pthread_mutex_lock(&lock);
	thread = pthread_self();
	setbuf(stdout, NULL);
	va_start(args, format);
	printf("[%lu] ", thread);
	vprintf(format, args);
	va_end(args);
	pthread_mutex_unlock(&lock);

	return (0);
}

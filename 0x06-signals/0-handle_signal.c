#include "signals.h"

/**
 * handler - handles for a given signal
 * @signal: is the given signal
 */
void handler(int signal)
{
	printf("Gotcha! [%d]\n", signal);
	fflush(stdout);
}

/**
 * handle_signal - set a handle function for the SIGINT signal
 * Return: 0 on success, -1 in failure
 */
int handle_signal(void)
{
	return (signal(SIGINT, handler) == SIG_ERR ? -1 : 0);
}

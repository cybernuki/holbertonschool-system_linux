#include "signals.h"

/**
 * signal_handler - handles for a given signal
 * @signal: is the given signal
 */
void signal_handler(int signal)
{
	printf("Gotcha! [%d]\n", signal);
	fflush(stdout);
}

/**
 * handle_sigaction - set a handle function for the SIGINT signal
 * Return: 0 on success, -1 in failure
 */
int handle_sigaction(void)
{
	struct sigaction handler;

	memset(&handler, 0, sizeof(handler));
	handler.sa_handler = &signal_handler;

	return (sigaction(SIGINT, &handler, NULL));
}

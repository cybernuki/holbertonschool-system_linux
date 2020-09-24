#include "signals.h"

/**
 * current_handler_sigaction - get the current handler for the SIGINT signal
 * Return: 0 on success, -1 in failure
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction current = {0};

	sigaction(SIGINT, NULL, &current);
	return (current.sa_handler);
}

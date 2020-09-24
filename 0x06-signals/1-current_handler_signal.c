#include "signals.h"

/**
 * current_handler_signal - set a handle function for the SIGINT signal
 * Return: the current handler of the signal SIGINT or null on failure
 */
void (*current_handler_signal(void))(int)
{
	void (*current)(int) = NULL;

	current = signal(SIGINT, NULL);
	signal(SIGINT, current);
	return (current);
}

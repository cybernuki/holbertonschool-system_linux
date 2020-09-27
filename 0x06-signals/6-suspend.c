#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * signal_handler - handles for a given signal
 * @signal: is the given signal
 */
void signal_handler(int signal)
{
	printf("Caught %d\n", signal);
	fflush(stdout);
}

/**
 * main - suspend the program until get SIGINT twice
 * Return: EXIT_SUCESS
 */
int main(void)
{
	struct sigaction handler;

	memset(&handler, 0, sizeof(handler));
	handler.sa_handler = &signal_handler;
	sigaction(SIGINT, &handler, NULL);

	pause();
	printf("Signal received\n");
	return (EXIT_SUCCESS);
}

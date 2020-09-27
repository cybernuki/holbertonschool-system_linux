#include "signals.h"

/**
 * action - is the action for the SIGQUIT signal
 * @signal: is the recieved signal
 * @info: is a struct with information about the sender of the signal
 * @context: is the context... whatever it is xddd
 */
void action(int signal, siginfo_t *info, void *context)
{
	(void)signal, (void)context;

	printf("SIGQUIT sent by %d\n", info->si_pid);
}

/**
 * trace_signal_sender - set handler for SIGQUIT signal
 * Return: 0 in success, -1 in failure
 */
int trace_signal_sender(void)
{
	struct sigaction act;

	memset(&act, 0, sizeof(act));
	act.sa_sigaction = action;
	act.sa_flags = SA_SIGINFO;

	return (sigaction(SIGQUIT, &act, NULL));
}

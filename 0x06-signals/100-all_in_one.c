#include "signals.h"

/**
 * signal_handler - handles signals
 * @signum: the signal number
 * @siginfo: info struct about signal
 * @ucontext: pointer to ucontext_t
 */
void signal_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	(void)signum, (void)ucontext;
	psiginfo(siginfo, "Caught");
}

/**
 * all_in_one - sets up a single handler for all the signals
 */
void all_in_one(void)
{
	struct sigaction action;
	int i;

	memset(&action, 0, sizeof(action));
	action.sa_flags |= SA_SIGINFO;
	action.sa_sigaction = signal_handler;

	for (i = 0; i <= 64; i++)
		sigaction(i, &action, NULL);
}

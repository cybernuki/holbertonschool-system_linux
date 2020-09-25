#include <signal.h>
#include <sys/types.h>

/**
 * pid_exist - test if the given pid correspond to a existing process
 * @pid: is the pid of the process
 * Return: 1 on success, 0 on fail
 */
int pid_exist(pid_t pid)
{
	return (!kill(pid, 0) ? 1 : 0);
}

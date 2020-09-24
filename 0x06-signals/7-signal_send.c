#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - send a signal SIGINT to a process, given its PID
 * @argc: is the argc
 * @argv: is the argv
 * Return: EXIT_SUCESS, EXIT_FAILURE
 */
int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s <pid>", argv[0]);
		exit(EXIT_FAILURE);
	}
	return (!kill(atoi(argv[1]), SIGINT) ? EXIT_SUCCESS : EXIT_FAILURE);
}

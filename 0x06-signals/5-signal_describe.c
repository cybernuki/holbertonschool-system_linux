#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - display a description for the given signal
 * @argc: is the argc
 * @argv: is the argv xd
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    char *description = NULL;

    if (argc < 2)
    {
        printf("Usage: %s <signum>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    description = strsignal(atoi(argv[1]));

    printf("%s: %s\n", argv[1], description);
    return (0);
}

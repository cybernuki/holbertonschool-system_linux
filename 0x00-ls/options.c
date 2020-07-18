#include "./options.h"
#include "./error_handler.h"

/**
 * close_options - This functions free the allocated options pointer.
 * @options: is the opened data structure
 */
void close_options(options *options)
{
	free(options);
}

/**
 * verify_options - It verify if a given options arguments are correct
 * If one of the chars is not an alias in the options array,
 * it exit the program with an error message;
 * @options: is the supported options
 * @input_options: It is the input arguments given by the user
 * to use in the command, it must be an null terminated string
 * Return: 0 if everything was fine, 1 if an error appears.
 */
int verify_options(options **options, const char *input_options)
{
	int i, j, found = 0;


	if (!options || !(*options) || !(*options)->aliases)
	{
		perror("error verifying flags");
		exit(98);
	}

	for (i = 0; input_options[i]; i++)
	{
		found = 0;
		for (j = 0; (*options)->aliases[j] && !found; j++)
		{
			if (input_options[i] == (*options)->aliases[j])
				found = 1;
			if (found)
			{
				/* This is very hardcode, modify later*/
				if ((*options)->aliases[j] == 'S')
					/*change 't' usage to 0*/
					(*options)->usages[6] = 0;
				else if ((*options)->aliases[j] == 't')
					/*change 'S' usage to 0*/
					(*options)->usages[5] = 0;
				(*options)->usages[j] = 1;
			}
		}
		if (!found)
		{
			error_handler(&input_options[i], INVALID_OPTION,
				      *options, NULL, NULL);
			return (1);
		}
	}
	return (0);
}

/**
 * init_options - This function initialize a instance of the options struct.
 * if there was an error allocating, it will exit and print the erro.
 * Return: an allocated options pointer.
 */
options *init_options()
{
	options *new = NULL;

	new = (options *) calloc(1, sizeof(options));

	if (!new)
	{
		perror("error allocating the options struct");
		exit(98);
	}

	new->aliases = "1laArStR\0";
	return (new);
}

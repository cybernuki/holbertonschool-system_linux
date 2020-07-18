#include "./parser.h"


/**
 * open_paths - initialize an paths struct
 * Return: an initialized paths structured
 */
paths *open_paths()
{
	paths *new =  NULL;
	int i = 0;

	new = (paths *) malloc(sizeof(paths));
	if (!new || !new->list)
	{
		perror("error allocating paths struct");
		return (NULL);
	}

	/* memset */
	for (i = 0; i < 1024; i++)
		new->list[i] = NULL;
	new->size = 0;

	return (new);
}

/**
 * close_paths - It frees a given paths
 * @paths: a given paths struct that has been opened.
 */
void close_paths(paths *paths)
{
	if (paths)
		free(paths);
}

/**
 * parser - It parses the arguments given to the program,
 * paths and option are pointers to the caller function as it modify the values
 * That's why paths and options must be initialized structs
 * It verify the options using verfy_options function and handle errors
 * After it deals with the non '-' start strings, that are files.
 * if there are any files argument, the './' path is added as default
 *
 * @size: Is the numbers in the 'args' param - 1
 * @args: contains the arguements given by the execution but
 * It must be from the position 1+ to don't count the first argument that is
 * the name of the program
 * @paths: It is a pointer to a given paths structure in the caller function
 * @options: is a pointer to a given options strcuture in the caller function
 * Returns: Nothing
 */
void parser(int size, char *args[], paths **paths, options **options)
{
	int i, error = 0;

	if (!(*options) || !paths)
	{
		perror("given struct is NULL\n");
		return;
	}

	*paths = open_paths();
	if (!*paths)
		return;

	for (i = 0; i < size; i++)
	{
		/* Strings with the form '-<char>' are options*/
		if (args[i][0] == '-' && args[i][1])
		{
			/* It verify wheter the option is correct*/
			error = verify_options(options, &args[i][1]);
			if (error)
			{
				close_paths(*paths);
				exit(2);
			}
		}
		/* otherwise, deal with it as paths*/
		else
		{
			/* It saves the string into the paths struct*/
			(*paths)->list[(*paths)->size] = args[i];
			(*paths)->size++;
		}
	}
	/* when any file args is found, it add the current directory */
	if (!(*paths)->size)
	{
		(*paths)->list[0] = "./";
		(*paths)->size++;
	}
}

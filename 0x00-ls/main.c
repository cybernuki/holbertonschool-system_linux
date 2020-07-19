#include "./options.h"
#include "./parser.h"
#include "./runner.h"

/**
 * main - main function
 * @argc: size of the argv array
 * @argv: array with commands
 * Return: 0 in success, another number in otherwise
 */
int main(int argc, char *argv[])
{
	int result = 0;
	paths *paths = NULL;
	options *options = NULL;

	options = init_options();

	parser(argc - 1, &argv[1], &paths, &options);


	result = runner(paths, options);
	close_paths(paths);
	close_options(options);

	if (result == -1)
		exit(2);
	exit(0);
}

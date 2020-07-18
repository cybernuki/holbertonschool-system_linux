#include "./headers/options.h"
#include "./headers/parser.h"
#include "./headers/runner.h"
#include "./headers/data_structures.h"

/**
 * main - main function
 * @argc: size of the argv array
 * @argv: array with commands
 * Return: 0 in success, another number in otherwise
 */
int main(int argc, char *argv[])
{
	paths *paths = NULL;
	options *options = NULL;

	options = init_options();

	parser(argc - 1, &argv[1], &paths, &options);


	runner(paths, options);
	close_paths(paths);
	close_options(options);
	exit(0);
}

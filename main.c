#include "./headers/options.h"
#include "./headers/parser.h"

int main (int argc, char *argv[]) {
	paths *paths = NULL;
	options *options = NULL;

	paths = open_paths();
	options = init_options();

	parser(argc - 1, &argv[1], &paths, &options);

	close_paths(paths);
	close_options(options);
	exit (0);
}

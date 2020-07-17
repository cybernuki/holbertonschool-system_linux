#include "./headers/options.h"
#include "./headers/parser.h"
#include <sys/types.h>
#include <dirent.h>


int main (int argc, char *argv[]) {
	paths *paths = NULL;
	options *options = NULL;
	DIR *dir = NULL;
	struct dirent *read;
	size_t i = 0;


	paths = open_paths();
	options = init_options();

	parser(argc - 1, &argv[1], &paths, &options);


	for (i = 0; i < paths->size; i++) {
		dir = opendir(paths->list[i]);

		while ((read = readdir(dir)) != NULL)
			printf("%s\n", read->d_name);
	}

	close_paths(paths);
	close_options(options);
	exit (0);
}

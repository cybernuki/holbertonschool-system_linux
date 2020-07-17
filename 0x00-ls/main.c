#include "./headers/options.h"
#include "./headers/parser.h"
#include "./headers/runner.h"
#include "./headers/data_structures.h"

int main (int argc, char *argv[]) {
	paths *paths = NULL;
	options *options = NULL;
	DIR *dir = NULL;
	struct dirent *read;
	size_t i = 0, j= 0;
	to_print *list = NULL, *node = NULL;

	paths = open_paths();
	options = init_options();

	parser(argc - 1, &argv[1], &paths, &options);


//	runner(paths, options);

	for (i = 0; i < paths->size; i++) {
		dir = opendir(paths->list[i]);
		while ((read = readdir(dir)) != NULL) {
			add_node(&list,read);
		}
		print_list(list);
/**		printf("removing index 0\n");
		remove_node(&list, 0);
		print_list(list);
		free_list(list);
*/	}
	close(dir);
	close_paths(paths);
	close_options(options);
	exit (0);
}

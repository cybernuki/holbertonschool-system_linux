#include "./headers/runner.h"

int permissions(char *path) {
	return (0);
}

int runner(paths *paths, options *options) {
	int result = 0, error = 0;
	size_t i = 0;
	struct dirent **files = NULL;

	/* Iterative */
	for (i = 0; i < paths->size; i++) {
		if (paths->size > 1)
			printf("%s:\n", paths->list[i]);
		/* Permisions */
		// error = permisions(paths->list[i]);
		/* Filter */
		// files = filter(paths->list[i]);
	}
	/* Recursion */
	return (result);
}

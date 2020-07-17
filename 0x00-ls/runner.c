#include "./headers/runner.h"
#include "./headers/error_handler.h"

// 1 is file, 2 is directory, -1 error
int check_path(char *path) {
	struct stat buf;
	int result = 0;

	result = lstat(path, &buf);

	if (result == -1)
	{
		error_handler(path, errno, NULL, NULL, NULL);
		return (-1);
	}

	switch (buf.st_mode & S_IFMT) {
	case S_IFDIR:
		result = 2;
		break;
	default:
		result = 1;
		break;
	}

	printf("result %d\n",result);
	return (result);
}


int runner(paths *paths, options *options) {
	int result = 0, error = 0;
	size_t i = 0;
	struct dirent **files = NULL;

	/* Iterative */
	for (i = 0; i < paths->size; i++) {
		if (paths->size > 1)
			printf("%s:\n", paths->list[i]);

		check_path(paths->list[i]);
		/* Permisions */
		// error = permisions(paths->list[i]);
		/* Filter */
		// files = filter(paths->list[i]);
	}
	/* Recursion */
	return (result);
}

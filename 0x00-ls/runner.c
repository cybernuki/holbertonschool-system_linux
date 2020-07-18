#include "./headers/runner.h"
#include "./headers/error_handler.h"
#include "./headers/data_structures.h"

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
	return (result);
}

to_print *get_dir(char *path, options *options)
{
	DIR *dir = NULL;
	struct dirent *read;
	to_print *list = NULL;
	char *name = NULL;
	int flag_a = 0, flag_A = 0;

	dir = opendir(path);

	flag_a = options->usages[INDEX_FLAG_a];
	flag_A = options->usages[INDEX_FLAG_A];
	while ((read = readdir(dir)) != NULL)
	{
		name = read->d_name;
		if (!flag_A && !flag_a && name[0] != '.')
			add_node(&list, read);
		else if (flag_A && !(name[0] == '.' && !name[1])
			 && !(name[0] == '.' && name[1] == '.'))
			add_node(&list, read);
		else if (flag_a)
			add_node(&list, read);
	}

	while (list){
		printf("%s\n", list->value->d_name);
		list = list->next;
	}
	return list;
}


int runner(paths *paths, options *options) {
	int result = 0, check = 0;
	size_t i = 0;
	struct dirent **files = NULL;
	to_print *list = NULL;

	/* Iterative */
	for (i = 0; i < paths->size; i++) {
		check = check_path(paths->list[i]);
		if (check == -1)
			continue;
		if (paths->size > 1)
                        printf("%s:\n", paths->list[i]);
		list = get_dir(paths->list[i], options);
	}
	/* Recursion */
	return (result);
}

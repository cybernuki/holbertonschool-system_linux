#include "./headers/runner.h"
#include "./headers/error_handler.h"
#include "./headers/data_structures.h"

/**
 * check_path - this function check wheter the path is a file
 * or a director. If some error appears due the access, it prints the error
 * @path: is a path string
 * Return: 0 if any error appears, -1 in otherwise.
 */
int check_path(char *path)
{
	struct stat buf;
	int result = 0;

	result = lstat(path, &buf);

	if (result == -1)
	{
		error_handler(path, errno, NULL, NULL, NULL);
		return (-1);
	}

	switch (buf.st_mode & S_IFMT)
	{
	case S_IFDIR:
		result = 2;
		break;
	default:
		result = 1;
		break;
	}
	return (result);
}

/**
 * get_dir - this function get the DIR struct with the information of the given
 * path, Also, it filter which files will be added to be printed by the given
 * flag options; 'a' and 'A'
 * @path: is the given path to open
 * @options: the options structure with the flags
 * Return: a filled to_print structure with the files to be printed;
 */
to_print *get_dir(char *path, options *options)
{
	DIR *dir = NULL;
	struct dirent *read = NULL;
	to_print *list = NULL, *index = NULL;
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

	index = list;
	while (index)
	{
		printf("%s\n", index->value->d_name);
		index = index->next;
	}

	closedir(dir);
	return (list);
}


/**
 * runner - it execute the process of print each paths
 * @paths: is the struct with the paths list
 * @options: is the struct with the options list
 * Return: 0 it any error appears, -1 otherwise
 */
int runner(paths *paths, options *options)
{
	int result = 0, check = 0;
	size_t i = 0;
	to_print *list = NULL;

	/* Iterative */
	for (i = 0; i < paths->size; i++)
	{
		check = check_path(paths->list[i]);
		if (check == -1)
			continue;
		if (paths->size > 1)
			printf("%s:\n", paths->list[i]);
		list = get_dir(paths->list[i], options);
		free_list(list);
	}
	/* Recursion */
	return (result);
}

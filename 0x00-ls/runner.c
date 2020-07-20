#include "./runner.h"
#include "./error_handler.h"
#include "./to_print_paths.h"
/**
 * check_path - this function check wheter the path is a file
 * or a director. If some error appears due the access, it prints the error
 * @path: is a path string
 * Return: 1 if it is an regular file, 2 if it is a dir, -1 in otherwise.
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
 * print_dirs - This function opens each dir in the dirs lists and prints their
 * content.
 * @dirs: is the given dirs paths list
 * @n_dirs: is the number of directories in the list
 * @options: the options structure with the flags
 */
void print_dirs(to_print *dirs, size_t n_dirs, options *options)
{
	DIR *dir = NULL;
	struct dirent *read = NULL;
	to_print *index = NULL;
	char *name = NULL;
/* This coudl be in the filter */
	int flag_a = 0, flag_A = 0;

	flag_a = options->usages[INDEX_FLAG_a];
	flag_A = options->usages[INDEX_FLAG_A];
	index = dirs;
	while (index)
	{
		dir = opendir(index->value);
		if (n_dirs >= 2)
			printf("%s:\n", index->value);
		while ((read = readdir(dir)) != NULL)
		{
			name = read->d_name;
			/*Filter, create a function apart*/
			if (!flag_A && !flag_a && name[0] != '.')
				printf("%s ", name);
			else if (flag_A && !(name[0] == '.' && !name[1])
				 && !(name[0] == '.' && name[1] == '.'))
				printf("%s ", name);
			else if (flag_a)
				printf("%s ", name);
		}
		if (n_dirs == 1 || !index->next)
			printf("\n");
		else
			printf("\n\n");
		closedir(dir);
		index = index->next;
	}
}

/**
 * print_files - prints all files in the files list
 * @files: is the given files list
 * @n_dirs: is the number of directories given
 */
void print_files(to_print *files, size_t n_dirs)
{
	to_print *inx = NULL;

	/* print regular files */
	inx = files;
	while (inx)
	{
		printf("%s ", inx->value);
		if (!inx->next && n_dirs)
			printf("\n\n");
		else if (!inx->next && !n_dirs)
			printf("\n");
		inx = inx->next;
	}
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
	size_t i = 0, n_dirs = 0;
	to_print *dirs = NULL;
	to_print *files = NULL;

	/* filtrar */
	for (i = 0; i < paths->size; i++)
	{
		check = check_path(paths->list[i]);
		if (check == -1)
		{
			result = check;
			continue;
		}
		else if (check == 1)
			add_node(&files, paths->list[i]);
		else
		{
			add_node(&dirs, paths->list[i]);
			n_dirs++;
		}
	}
	/* sortear*/

	/* imprimir*/
	print_files(files, n_dirs);
	print_dirs(dirs, n_dirs, options);

	free_list(dirs);
	free_list(files);
	return (result);
}

#include "./runner.h"
#include "./error_handler.h"
#include "./to_print_dirs.h"
#include "./to_print_files.h"

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
 * get_dir - this function get the DIR struct with the information of the given
 * path, Also, it filter which files will be added to be printed by the given
 * flag options; 'a' and 'A'
 * @path: is the given path to open
 * @options: the options structure with the flags
 * Return: a filled to_print structure with the files to be printed;
 */
to_print_dirs *get_dir(char *path, options *options)
{
	DIR *dir = NULL;
	struct dirent *read = NULL;
	to_print_dirs *list = NULL;
	char *name = NULL;
	int flag_a = 0, flag_A = 0;

	dir = opendir(path);

	flag_a = options->usages[INDEX_FLAG_a];
	flag_A = options->usages[INDEX_FLAG_A];
	while ((read = readdir(dir)) != NULL)
	{
		name = read->d_name;
		if (!flag_A && !flag_a && name[0] != '.')
			add_node(&list, read, path);
		else if (flag_A && !(name[0] == '.' && !name[1])
			 && !(name[0] == '.' && name[1] == '.'))
			add_node(&list, read, path);
		else if (flag_a)
			add_node(&list, read, path);
	}
	closedir(dir);
	return (list);
}

/**
 * print_ls - prints the files and directories as the ls command
 * @dirs: is an array with all dirs
 * @n_dirs: is the size of dirs
 * @files: is the list with all files
 */
void print_ls(to_print_dirs **dirs, size_t n_dirs, to_print_files *files)
{
	to_print_dirs *aux = NULL;
	to_print_files *inx = NULL;
	size_t i = 0;

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
	/* print directory files */
	for (i = 0; i < n_dirs; i++)
	{
		aux = dirs[i];
		if (n_dirs >= 2)
			/*printf("%s:\n", aux->dir_(name);)*/
		while (aux)
		{
			printf("%s ", aux->value->d_name);
			aux = aux->next;
		}
		printf("\n\n");
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
	to_print_dirs *dirs[1024];
	to_print_files *files = NULL;

	for (i = 0; i < 1024; i++)
		dirs[i] = NULL;
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
			add_node_files(&files, paths->list[i]);
		else
			dirs[n_dirs++] = get_dir(paths->list[i], options);
	}
	/* sortear*/

	/* imprimir*/
	print_ls(dirs, n_dirs, files);
	for (i = 0; i < n_dirs; i++)
		free_list(dirs[i]);

	free_list_files(files);
	return (result);
}

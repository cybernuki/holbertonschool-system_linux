#include "./headers/error_handler.h"

/**
 * invalid_option_error - This function prints the ls error when a bad
 * or not implemented option is given by the user. For instance '--' option
 * @item: is the bad char option
 * @options: is the options structure to be freeded
 */
void invalid_option_error(const char item, options *options)
{
	fprintf(stderr, "hls: invalid option -- '%c'\n", item);
	fprintf(stderr, "try 'hls --help' for more information.\n");
	close_options(options);
}

/**
 * not_permissions_error - This function prints the ls error when the path
 * contains privilage grater that the current user
 * @item: is the path
 */
void not_permissions_error(const char *item)
{
	fprintf(stderr, "hls: cannot open directory %s: Permission denied\n",
		item);
}

/**
 * not_access_error - This function prints the ls error when the path
 * Don't exist
 * @item: is the path
 */
void not_access_error(const char *item)
{
	fprintf(stderr, "hls: cannot access %s: No such file or directory\n",
		item);
}

/**
 * error_handler - This function prints errors to the stderr based on
 * and supported error code.
 * Right now, it can handle the errors:
 * INVALID_OPTION - see ./options.h
 *
 * @item: the item that provoqued the issue
 * @code: is the code of the error, you can provide yours or use the `errno`
 * @options: options structure, it could be provided or NULL,
 * it is used to be freed
 * @paths: paths structure, it could be provided or NULL,
 * it is used to be freed
 * @list: to_print structure, it could be provided or NULL,
 * it is used to be freed
 */
void error_handler(const char *item, int code, options *options,
		   paths *paths, to_print *list)
{
	(void) paths;
	(void) list;

	switch (code)
	{
	case INVALID_OPTION:
		invalid_option_error(item[0], options);
		break;
	case EACCES:
		not_permissions_error(item);
		break;
	case ENOENT:
		not_access_error(item);
		break;
	}
}

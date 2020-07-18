#include "./headers/error_handler.h"

void invalid_option_error(const char item, options *options)
{
	fprintf(stderr,"hls: invalid option -- '%c'\n", item);
	fprintf(stderr,"try 'hls --help' for more information.\n");
	close_options(options);
}

void not_permissions_error(const char *item)
{
	fprintf(stderr,"hls: cannot open directory %s: Permission denied\n",
		item);
}

void not_access_error(const char *item)
{
	fprintf(stderr, "hls: cannot access %s: No such file or directory\n",
		item);
}

void error_handler(const char *item, int code, options *options,
		   paths *paths, to_print *list)
{
	(void) paths;
	(void) list;

	switch (code) {
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

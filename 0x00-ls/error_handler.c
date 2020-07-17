#include "./headers/error_handler.h"

void invalid_option_error(char item, options *options)
{
	fprintf(stderr,"hls: invalid option -- '%c'\n", item);
	fprintf(stderr,"try 'hls --help' for more information.\n");
	close_options(options);
}

void error_handler(const char *item, int code, options *options,
		   paths *paths, to_print *list)
{
	if (code == INVALID_OPTION)
		invalid_option_error(item[0], options);
}

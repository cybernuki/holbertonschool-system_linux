#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <stdio.h>
#include "./parser.h"
#include "./options.h"
#include "./data_structures.h"

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
Void error_handler(const char *item, int code,options *options,
		   paths *paths, to_print *list);


/**
 * invalid_option_error - This functions prints the ls error when a bad
 * or not implemented option is given by the user. For instance '--' option
 * @item: is the bad char option
 * @options: is the options structure to be freeded
 */
void invalid_option_error(char item, options *options);

#endif

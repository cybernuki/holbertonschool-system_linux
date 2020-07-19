#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <stdio.h>
#include "./parser.h"
#include "./options.h"
#include "./to_print_dirs.h"
#include <sys/stat.h>
#include <errno.h>


void error_handler(const char *, int, options *, paths *, to_print_dirs *);


/**
 * invalid_option_error - This function prints the ls error when a bad
 * or not implemented option is given by the user. For instance '--' option
 * @item: is the bad char option
 * @options: is the options structure to be freeded
 */
void invalid_option_error(char item, options *options);

/**
 * not_permissions_error - This function prints the ls error when the path
 * contains privilage grater that the current user
 * @item: is the path
 */
void not_permissions_error(const char *item);

/**
 * not_access_error - This function prints the ls error when the path
 * Don't exist
 * @item: is the path
 */
void not_access_error(const char *item);
#endif

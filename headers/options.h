#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdlib.h>
#include <stdio.h>

/**
 * options - helps to contains the aliases of the supported flags.
 * It, also, contains which options to execute.
 * @aliases: it is the string with the chars that represent options
 * @usages: it is a binary array, every postion must correspond
 *          with the position of the alias char.
 */
typedef struct option_struct {
	char *aliases;
	short usages[8];
} options;

/**
 * init_options - This function initialize a instance of the options struct.
 * if there was an error allocating, it will exit and print the erro.
 * Returns: an allocated options pointer.
 */
options *init_options();


/**
 * close_options - This functions free the allocated options pointer.
 */
void close_options(options *options);

/**
 * verfy_options - It verify if a given options arguments are correct
 * If one of the chars is not an alias in the options array,
 * it exit the program with an error message;
 * @options: is the supported options
 * @input_options: It is the input arguments given by the user
 * to use in the command, it must be an null terminated string
 */
void verify_options(options **options,const char *input_options);

#endif

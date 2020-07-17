#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include "./options.h"

/**
 * paths - It is a struct that contains the file paths
 * @list - Contains the given paths
 * @size - It is the current number op paths in the list member.
 */
typedef struct paths_struct {
	char *list[1024];
	size_t size;
} paths;

/**
 * parser - It parses the arguments given to the program,
 * paths and option are pointers to the caller function as it modify the values.
 * That's why paths and options must be initialized structs
 * It verify the options using verfy_options function and handle errors
 * After it deals with the non '-' start strings, that are files.
 * if there are any files argument, the './' path is added as default
 *
 * @size Is the numbers in the 'args' param - 1
 * @args contains the arguements given by the execution but
 * It must be from the position 1+ to don't count the first argument that is
 * the name of the program
 * @paths: It is a pointer to a given paths structure in the caller function
 * @options: It is a pointer to a given options strcuture in the caller function
 * Returns: Nothing
 */
void parser(int size, char *args[], paths **paths, options **options);


/**
 * open_paths - initialize an paths struct
 */
paths *open_paths();

/**
 * close_paths - It frees a given paths
 * @paths: a given paths struct that has been opened.
 */
void close_paths(paths *paths);



#endif

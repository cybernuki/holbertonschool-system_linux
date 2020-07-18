#ifndef RUNNER_H
#define RUNNER_H

#include "./options.h"
#include "./parser.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * runner - it execute the process of print each paths
 * @paths: is the struct with the paths list
 * @options: is the struct with the options list
 * Return: 0 it any error appears, -1 otherwise
 */
int runner(paths *paths, options *options);


/**
 * check_path - this function check wheter the path is a file
 * or a director. If some error appears due the access, it prints the error
 * @path: is a path string
 * Return: 0 if any error appears, -1 in otherwise.
 */
int check_path(char *path);

struct dirent **filter(char *path);

struct dirent **order(struct dirent **files);

int format(struct dirent **files);

#endif

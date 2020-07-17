#ifndef RUNNER_H
#define RUNNER_H

#include "./options.h"
#include "./parser.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>


int runner(paths *paths, options *options);

int permissions(char *path);

struct dirent **filter(char *path);

struct dirent **order(struct dirent **files);

int format(struct dirent **files);

#endif

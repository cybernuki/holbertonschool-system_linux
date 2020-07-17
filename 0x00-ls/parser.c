#include "./headers/parser.h"

paths *open_paths() {
        paths *new =  NULL;

        new = (paths*) malloc(sizeof(paths));
        if(!new) {
                perror("error allocating paths struct");
                return NULL;
        }
        return new;
}

void close_paths(paths *paths) {
        free(paths);
}

void parser(int size,char *args[], paths **paths, options **options) {
        int i, error = 0;

	if (!(*options)) {
		perror("given struct is NULL\n");
		return;
	}

	*paths = open_paths();

        for (i = 0; i < size; i++) {
		/* Strings with the form '-<char>' are options*/
		if (args[i][0] == '-' && args[i][1]) {
                        /* It verify wheter the option is correct*/
			error = verify_options(options, &args[i][1]);
			if (error) {
				close_paths(*paths);
				exit(127);
			}
		}
		/* otherwise, deal with it as paths*/
		else {
			/* It saves the string into the paths struct*/
			(*paths)->list[(*paths)->size] = args[i];
			(*paths)->size ++;
		}
        }

	/* when any file args is found, it add the current directory */
	if (!(*paths)->size) {
		(*paths)->list[0] = "./";
		(*paths)->size ++;
	}
}

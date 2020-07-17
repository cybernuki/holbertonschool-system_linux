#include "./headers/options.h"
#include "./headers/error_handler.h"

void close_options(options *options) {
        free(options);
}

int verify_options(options **options, const char *input_options){
	int i, j, found = 0;


	if (!options || !(*options) || !(*options)->aliases) {
		perror("error verifying flags");
		exit (98);
	}

	for (i = 0; input_options[i]; i++) {
		found = 0;
		for (j = 0; (*options)->aliases[j] && !found; j++) {
			if (input_options[i] == (*options)->aliases[j])
				found = 1;
			if (found) {
				/* This is very hardcode, modify later*/
				if ((*options)->aliases[j] == 'S')
					/*change 't' usage to 0*/
					(*options)->usages[6] = 0;
				else if ((*options)->aliases[j] == 't')
					/*change 'S' usage to 0*/
					(*options)->usages[5] = 0;
				(*options)->usages[j] = 1;
			}
		}
		if (!found) {
			error_handler(&input_options[i], INVALID_OPTION,
				      *options, NULL, NULL);
			return (1);
		}
	}
	return (0);
}

options *init_options() {
        options *new = NULL;

        new = (options *) malloc(sizeof(options));

        if (!new) {
                perror("error allocating the options struct");
                exit(98);
        }

        new->aliases = "1laArStR\0";
        return new;
}

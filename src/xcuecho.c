#include <stdio.h>
#include <errno.h>
#include <unistd.h>

/*
 * This simple tool aims to recreate GNU-coreutil 'ECHO'
 *
 * Functionality: The echo command takes a String argument and prints this 
 * back to the terminal as output.
 * 
 * The real GNU coreutil exits and returns 0 if no arguments are provided.
 * In my tools I want to always show the use case if ran without arguments.
 */

int main(int argc, char *argv[]) {
    // this checks if the user put any arguments, if not it writes an error to the screen
	if (argc < 2) {
        fprintf(stderr, "usage: %s [-a] [text]\n", argv[0]);
        return 1;
    }

    int argument;


	while ((argument = getopt(argc, argv, "a")) != -1) {
		switch (argument) {
			case 'a':
				printf("Succesfully registered 'a' as command\n");
				break;
			default:
				return 1;
		}
	}

    // I still dont fully understand this line of code.
    for (int i = optind; i < argc; i++) {
        printf("%s", argv[i]);

        if (i < argc - 1) {
            printf(" ");
        }
    }

    printf("\n");

	return 0;
}

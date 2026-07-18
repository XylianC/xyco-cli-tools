#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>

#include "xcutils.h"
/* =============================================
		MY OWN LS TOOL 
		This is the start of a series of programs I write to make my own terminal utils.
		Specifically the goal is to learn how they work by duplicating their behaviour
		I hope to learn to use manpages, linux kernel behaviour,  c programming language
		maybe even... vim! :) 

		LS behaviour: 



		XYCO LS behaviour: 


============================================= */		

//	--- Notes --- //
// to learn; S_ISDIR
// dirent.h
// erno.h
// unistd.h
// sys/stat.h



// things learned, take arguments like -a when executing a project (int argc, char *argv[])
// why is * used? hmmm


int show_all = 0;


int main (int argc, char *argv[]) {
	print_header("LS");

    int opt;


	while ((opt = getopt(argc, argv, "a")) != -1){
		switch (opt) {
			case 'a':
				show_all = 1;
				break;
			default:
				fprintf(stderr, "usage: %s [-a] [path]\n", argv[0]);
				return 1;
		}
	}

	const char *path = (optind < argc) ? argv[optind] : ".";

	// dir is the current directory
	DIR *dir = opendir(path);
	if(!dir) {
		perror("opendir");
		return 1;
	}

	struct dirent *entry;

	while((entry = readdir(dir)) != NULL) {
		if(!show_all && entry->d_name[0] == '.') continue;
		printf("%s\n", entry->d_name);

	}

	entry = readdir(dir);

	closedir(dir);

	return 0;
}

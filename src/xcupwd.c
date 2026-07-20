#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "xcutils.h"

/* 
 * This simple tool aims to recreate GNU-coreutil 'PWD'
 *
 * Functionality: the pwd command makes a systemcall to the kernel and asks what
 * the current working directory is, it then displays this back to the user as 
 * a string output
 */

int main(int argc, char *argv[]) {
  int debug_enabled = 0;
  int arguments;

  if (argc > 2) {
    fprintf(stderr, "usage: %s [-d] \n", argv[0]);
    return 1;
  }

  while ((arguments = getopt(argc, argv, "d")) != -1) {
		switch (arguments){
			case 'd':
        debug_enabled = 1;
        break;
      default:
        break;
    }
  }

  if(debug_enabled) {
    print_debugs(argv[0]);
  }

  char cwd[100];
  if (getcwd(cwd, 100) != NULL) {
        fprintf(stdout, "%s\n", cwd);
  }
  else {
    // perror("pwd failed!\n");
    fprintf(stderr, "pwd failed to fetch present working directory\n");
    return 1;
    }
}

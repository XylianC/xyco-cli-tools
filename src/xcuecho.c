#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>
#include "xcutils.h"

/*
 * This simple tool aims to recreate GNU-coreutil 'ECHO'
 *
 * Functionality: The echo command takes a String argument and prints this 
 * back to the terminal as output.
 * 
 * The real GNU coreutil exits and returns 0 if no arguments are provided.
 * In my coreutils tools I want to always show the use case if ran without arguments.
 */

int main(int argc, char *argv[]) {
  // this checks if the user put any arguments, if not it writes an error to the screen
  if (argc < 2) {
    fprintf(stderr, "usage: %s [-a,u,l,r,d] [text]\n", argv[0]);    
    return 1;
  }

  int arguments;
  int is_ascii = 0;
  int is_uppercase = 0;
  int is_lowercase = 0;
  int is_reverse = 0;
  int debug_enabled = 0;

	while ((arguments = getopt(argc, argv, "aulrd")) != -1) {
		switch (arguments) {
			case 'a':
        break;
      case 'u':
        is_uppercase = 1;
        break;
      case 'l':
        is_lowercase = 1;
        break;
      case 'r':
        is_reverse = 1;
        break;
      case 'd':
        debug_enabled = 1;
        break;
      default:
				return 1;
		  }
	}

  if(debug_enabled) {
    print_debugs(argv[0]);
  }

    // I still dont fully understand thes line of code.
  if(is_uppercase == 1) {
    for (int i = optind; i < argc; i++) {
      printf("%s", argv[i]);

      if (i < argc - 1) {
        printf(" ");
      }
    }
  
    if(debug_enabled) {
        print_debug_message("... but to UPPERCASE ofcourse! :)");    
      } 
  }
    
  if (is_lowercase == 1) {
    for (int i = optind; i < argc; i++) {
      printf("%s", argv[i]);

      if (i < argc - 1) {
        printf(" ");
      }
    }
    
    if(debug_enabled) {
      print_debug_message("... but to lowercase ofcourse! :)");    
    }
  } 

  if (is_lowercase == 0 && is_uppercase == 0) {
    for (int i = optind; i < argc; i++) {
      printf("%s", argv[i]);

      if (i < argc - 1) {
        printf(" ");
      }
    } 
  
    if(debug_enabled) { 
      print_debug_message("... but normally ofcourse! :)");
    }
  }


  if (is_reverse) {
    for (int i = optind; i < argc; i++) {
      printf("%s", argv[i]);

      if (i < argc - 1) {
        printf(" ");
      }
    }
    
    if(debug_enabled) {
      print_debug_message("... but in reverse ofcourse! :)");
    }
  }
    
  if (is_ascii) {
    for (int i = optind; i < argc; i++) {
      printf("%s", argv[i]);

      if (i < argc - 1) {
        printf(" ");
      }
    }
    
    if(debug_enabled) {
      print_debug_message("... but with ascii codes ofcourse! :)");
    }
  }

  printf("\n");

  if(debug_enabled) {print_application_end();}
	return 0;
}

#include <stdio.h>
#include "xcutils.h"

void print_header(char *program_name) {
    printf("--- Application ----\n");
    printf("XCU-utils: %s\n", program_name);
    printf("------\n");
}

void print_application_start(char *program_name) {
  printf("- DB: Application Name: -%s\n", program_name);
  printf("- DB: Application Arguments: \n");
  printf("- DB: Application: \n\n");
}


void print_application_end() {
  printf("--------------- \n");
  printf("- DB: Application finished!\n");
}

void print_debug_message(char *db_message) {
  printf("\n- DB: %s\n", db_message);
}

void print_debugs(char *program_name) {
  printf("---------- DEBUG MENU ----------\n");
  print_application_start(program_name);
}

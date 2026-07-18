#include <stdio.h>

#include "xcutils.h"

/* 
 * This simple tool aims to recreate GNU-coreutil 'PWD'
 *
 * Functionality: the pwd command makes a systemcall to the kernel and asks what
 * the current working directory is, it then displays this back to the user as 
 * a string output
 */

int main(int argc, char *argv[]) {
    print_header("PWD");
}

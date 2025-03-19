#include "String.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Prints a string to the console.
 * 
 * @param str The string to be printed.
 */
void print(char* str) {
    printf("%s", str);
}

/**
 * Prints a string to the console followed by a newline character.
 * 
 * @param str The string to be printed.
 */
void println(char* str){
    print(str);
    printf("\n");
}
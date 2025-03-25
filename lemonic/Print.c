#include "LString.h"
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

/**
 * Prints a newline character to the console.
 */
void printn() {
    printf("\n");
}

/**
 * Prints an LString to the console.
 * 
 * @param str A pointer to the LString to be printed.
 */
void printS(LString* str) {
    printf("%s", str->str);
}

/**
 * Prints an LString to the console followed by a newline character.
 * 
 * @param str A pointer to the LString to be printed.
 */
void printSln(LString* str) {
    printS(str);
    printf("\n");
}
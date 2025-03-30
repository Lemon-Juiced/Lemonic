#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcomp_prototypes.h"

/**
 * Removes the path from a given filename.
 * Works for Linux, Mac, and Windows.
 * 
 * @param filename The name of the file to be processed.
 * @return A pointer to the filename without the path.
 */
char *removePath(const char *filename) {
    char pathSeparator = '/'; // Default path separator for Linux and Mac
    #ifdef _WIN32
        pathSeparator = '\\'; // Path separator for Windows
    #endif

    char *baseName = strrchr(filename, pathSeparator);
    if (baseName != NULL) {
        baseName++; // Move past the path separator
    } else {
        baseName = (char *)filename; // No path, use the full name
    }
    return baseName;
}

/**
 * Confirms that a given file is a valid Lemonic file.
 * 
 * @param filename The name of the file to be checked.
 * @return 1 if the file is valid, 0 if not.
 */
int isValidLemonicFile(const char *filename) {
    // Check if the file has a .lmc extension
    const char *extension = strrchr(filename, '.');
    if (extension != NULL && strcmp(extension, ".lmc") == 0) {
        return 1; // Valid Lemonic file
    }
    return 0; // Invalid Lemonic file
}

/**
 * Sets the output file name in the ProgamInfo struct.
 * If the output file is not provided, it uses the input file name without the .lmc extension.
 * 
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @param programInfo The ProgamInfo struct to be updated.
 */
void setOutputFileName(int argc, char *argv[], ProgamInfo *programInfo) {
    if (argc >= 3 && argv[2][0] != '-') {
        programInfo->outputFile = argv[2]; // The output file name
    } else {
        // If the output file is not provided, use the input file name without the .lmc extension
        programInfo->outputFile = (char *)malloc(strlen(argv[1]) + 1); // +1 for null terminator
        strcpy(programInfo->outputFile, argv[1]);
        char *extension = strrchr(programInfo->outputFile, '.');
        if (extension != NULL) {
            *extension = '\0'; // Remove the old extension
        }
    }
}

/**
 * Prints the tokens to the console.
 * 
 * @param tokens The array of tokens to be printed.
 * @param token_count The number of tokens in the array.
 */
void printTokens(Token* tokens, unsigned long token_count){
    for (unsigned long i = 0; i < token_count; i++) {
        printf("Token %lu: Value: %s, Type: %s, Line: %d\n", i + 1, tokens[i].value, tokens[i].type, tokens[i].line);
    } 
}

/**
 * Frees the memory allocated for the tokens.
 * 
 * @param tokens The array of tokens to be freed.
 * @param token_count The number of tokens in the array.
 */
void freeTokens(Token* tokens, unsigned long token_count){
    for (unsigned long i = 0; i < token_count; i++) {
        free(tokens[i].value); // Free the value string
        free(tokens[i].type); // Free the type string
    }
    free(tokens); // Free the tokens array
}
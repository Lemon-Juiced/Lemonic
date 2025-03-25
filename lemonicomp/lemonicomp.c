#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcomp_prototypes.h"
#include "lcomp_structs.h"

/**
 * Main function of the lemonicomp compiler.
 * The lemonicomp compiler is a compiler for the Lemonic programming language.
 * The compiler in this case is more of a translator that translates Lemonic code to C code.
 * This compiler will continue to evolve with the Lemonic programming language.
 * 
 * Usage:
 * lemonicomp <input_file.lmc> <output_file> (optional) [-c]
 * argv[0] = <lemonicomp> (required) This program 
 * argv[1] = <input_file.lmc> (required) The input file name
 * argv[2] = <output_file> (optional) The output file name
 * argv[3] = [-c] (optional) The generated C code will not be deleted after compilation.
 * 
 * Additional Arguments:
 * -c: The generated C code will not be deleted after compilation. (Default behavior is to delete the C code after compilation.)
 * 
 * Steps:
 * 1. Check if the correct number of arguments is provided.
 * 2. Check if the input file is a valid Lemonic file.
 * 3. Store arguments provided to the compiler as a struct.
 *    This is a little messy as the number of arguments is not fixed.
 * ...
 * Unknown Step. Add as EOL comments in the C file that reference the line from the Lemonic file, for error handling.
 * ...
 * n-1. If the -c flag is not provided, delete the C file after compilation.
 * n. Hand the newly created C file to the C compiler.
 * 
 * @argc The number of command line arguments.
 * @argv The command line arguments.
 * @return 0 if successful, 1 if an error occurred.
 */
int main(int argc, char *argv[]) {    // 1. Check if the correct number of arguments is provided
    if (argc < 2 || argc > 4) {
        // Get the name of the program from argv[0], but remove the path from it.
        char *programName = removePath(argv[0]);
        fprintf(stderr, "Usage: %s <input_file.lmc> <output_file> (optional) [-c]\n", programName);
        return 1;
    }

    // 2. Check if the input file is a valid Lemonic file
    if (!isValidLemonicFile(argv[1])) {
        fprintf(stderr, "Error: Invalid Lemonic file.\nPlease provide a .lmc file.\n");
        return 1;
    }

    // 3. Store arguments provided to the compiler as a struct.
    ProgamInfo programInfo;
    programInfo.initialNumberOfArgs = argc;
    programInfo.inputFile = argv[1];
    programInfo.keepCFile = false;

    // Check if the output file is provided and set the name appropriately.
    setOutputFileName(argc, argv, &programInfo);

    // Check if the -c flag is provided.
    if ((argc == 4 && strcmp(argv[3], "-c") == 0) || (argc == 3 && strcmp(argv[2], "-c") == 0)) {
        programInfo.keepCFile = true;
    }

    // Create a new C file with the same name as the input file, but with a .c extension
    char *cFileName = (char *)malloc(strlen(programInfo.outputFile) + 3);
    if (cFileName == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for C file name.\n");
        return 1;
    }
    strcpy(cFileName, programInfo.outputFile);
    strcat(cFileName, ".c");
    FILE *cFile = fopen(cFileName, "w");
    if (cFile == NULL) {
        fprintf(stderr, "Error: Could not create output file.\n");
        free(cFileName);
        return 1;
    }

    // Open the input file for reading
    FILE *inputFile = fopen(programInfo.inputFile, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: Could not open input file.\n");
        fclose(cFile);
        free(cFileName);
        return 1;
    }

    // Read the input file and write the C code to the output file
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        fputs(buffer, cFile);
    }

    // Close the input file after reading
    fclose(inputFile);

    // Close the output file
    fclose(cFile);

    // If the -c flag is not provided, delete the C file after compilation
    if (programInfo.keepCFile == false) {
        if (remove(cFileName) != 0) {
            fprintf(stderr, "Error: Could not delete output file.\n");
            free(cFileName);
            return 1;
        }
    }

    free(cFileName);
    return 0; // Success
}
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    // Data Members
    int initialNumberOfArgs; // The initial number of arguments
    char *inputFile; // The input file name
    char *outputFile; // The output file name
    bool keepCFile; // Flag to keep the C file after compilation
} ProgamInfo;

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
int main(int argc, char *argv[]) {
    // 1. Check if the correct number of arguments is provided
    if (argc < 2 || argc > 4) {
        // Get the name of the program from argv[0], but remove the path from it.
        char *programName = removePath(argv[0]);
        fprintf(stderr, "Usage: %s <input_file.lmc> <output_file> (optional) [-c]\n", programName); // progamName is printed with %s so Linux/Mac will not print with ".exe" like Windows.
        return 1;
    }

    // 2. Check if the input file is a valid Lemonic file
    // We could do this after the struct is created, but its cleaner to do it here.
    if (!isValidLemonicFile(argv[1])) {
        fprintf(stderr, "Error: Invalid Lemonic file.\nPlease provide a .lmc file.\n");
        return 1;
    }

    // 3. Store arguments provided to the compiler as a struct.
    // Create a struct to store the program information and get the information we know must exist.
    ProgamInfo programInfo;
    programInfo.initialNumberOfArgs = argc; // The initial number of arguments
    programInfo.inputFile = argv[1]; // The input file name
    programInfo.keepCFile = false; // Default to not keeping the C file

    // Check if the output file is provided and set the name appropriately.
    setOutputFileName(argc, argv, &programInfo);

    // Debug print to check the output file name
    //printf("Output file name: %s\n", programInfo.outputFile);

    // Check if the -c flag is provided.
    if ((argc == 4 && strcmp(argv[3], "-c") == 0) || (argc == 3 && strcmp(argv[2], "-c") == 0)) {
        programInfo.keepCFile = true; // Set the flag to keep the C file
    }

    // Create a new C file with the same name as the input file, but with a .c extension
    char *cFileName = (char *)malloc(strlen(programInfo.outputFile) + 3); // +3 for ".c" and null terminator
    if (cFileName == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for C file name.\n");
        return 1;
    }
    strcpy(cFileName, programInfo.outputFile); // Copy the output file name
    strcat(cFileName, ".c"); // Add the new extension
    //printf("C file name: %s\n", cFileName); // Debug print to check the C file name
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
        // Delete the C file after compilation
        if (remove(cFileName) != 0) {
            fprintf(stderr, "Error: Could not delete output file.\n");
            free(cFileName);
            return 1;
        }
    }

    free(cFileName);
    return 0; // Success
}
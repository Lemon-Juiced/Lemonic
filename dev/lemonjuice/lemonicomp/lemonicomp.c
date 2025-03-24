#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * Main function of the lemonicomp compiler.
 * The lemonicomp compiler is a compiler for the Lemonic programming language.
 * The compiler in this case is more of a translator that translates Lemonic code to C code.
 * This compiler will continue to evolve with the Lemonic programming language.
 * 
 * Additional Arguments:
 * -c: The generated C code will not be deleted after compilation. (Default behavior is to delete the C code after compilation.)
 * 
 * Steps:
 * 1. Check if the correct number of arguments is provided.
 * 2. Check if the -c flag is provided.
 * 3. Check if the input file is a valid Lemonic file.
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
    // Check if the correct number of arguments is provided
    if (argc < 2 || argc > 3) {
        // Get the name of the program from argv[0], but remove the path from it.
        char *programName = removePath(argv[0]);
        fprintf(stderr, "Usage: %s <input_file.lmc> [-c]\n", programName);
        return 1;
    }

    // Check if the -c flag is provided
    int keepCFile = 0;
    if (argc == 3 && strcmp(argv[2], "-c") == 0) {
        keepCFile = 1;
    }

    // Check if the input file is a valid Lemonic file
    if (!isValidLemonicFile(argv[1])) {
        fprintf(stderr, "Error: Invalid Lemonic file.\nPlease provide a .lmc file.\n");
        return 1;
    }

    // Create a new C file with the same name as the input file, but with a .c extension
    char *inputFileName = argv[1];
    char *outputFileName = (char *)malloc(strlen(inputFileName) + 2); // +2 for .c and null terminator
    strcpy(outputFileName, inputFileName);
    char *extension = strrchr(outputFileName, '.');
    if (extension != NULL) {
        *extension = '\0'; // Remove the old extension
    }
    strcat(outputFileName, ".c"); // Add the new extension
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Could not create output file.\n");
        free(outputFileName);
        return 1;
    }

    // Open the input file for reading

    // Close the input file after reading

    // Write the C code to the output file

    // Close the output file
    fclose(outputFile);

    // If the -c flag is not provided, delete the C file after compilation
    if (!keepCFile) {
        // Delete the C file after compilation
        if (remove(outputFileName) != 0) {
            fprintf(stderr, "Error: Could not delete output file.\n");
            fclose(outputFile);
            free(outputFileName);
            return 1;
        }
    }

    return 0; // Success
}
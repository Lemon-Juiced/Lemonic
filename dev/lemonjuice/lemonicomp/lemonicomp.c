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
 * Steps:
 * 1. Check if the correct number of arguments is provided.
 * 2. Check if the input file is a valid Lemonic file.
 * ...
 * Unknown Step. Add as EOL comments in the C file that reference the line from the Lemonic file, for error handling.
 * ...
 * Last. Hand the newly created C file to the C compiler.
 * 
 * @argc The number of command line arguments.
 * @argv The command line arguments.
 * @return 0 if successful, 1 if an error occurred.
 */
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    // This is naively done for now; this could easily chnage when Lemonic supports more than one file.
    if (argc != 2) {
        // Get the name of the program from argv[0], but remove the path from it.
        char *programName = removePath(argv[0]);
        fprintf(stderr, "Usage: %s <input_file.lmc>\n", programName);
        return 1;
    }

    // Check if the input file is a valid Lemonic file
    if (!isValidLemonicFile(argv[1])) {
        fprintf(stderr, "Error: Invalid Lemonic file.\nPlease provide a .lmc file.\n");
        return 1;
    }

    return 0; // Success
}
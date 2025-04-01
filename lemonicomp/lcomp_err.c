#include "lcomp_err.h"

// Ansi color codes for terminal output
char RED[] = "\x1b[31m"; // Red color for error messages
char YELLOW[] = "\x1b[33m"; // Yellow color for warnings
char RESET[] = "\x1b[0m"; // Reset color

/**
 * Prints an error message to the console and exits the program.
 * 
 * @param errorMessage The error message to be printed.
 */
void printError(char* errorMessage) {
    fprintf(stderr, "%sError: %s%s\n", RED, errorMessage, RESET);
    exit(EXIT_FAILURE);
}

/**
 * Prints an error message to the console with a line number and exits the program.
 * 
 * @param errorMessage The error message to be printed.
 * @param lineNumber The line number where the error occurred.
 */
void printErrorAtLine(char* errorMessage, int lineNumber) {
    fprintf(stderr, "%sError: %s at line %d%s\n", RED, errorMessage, lineNumber, RESET);
    exit(EXIT_FAILURE);
}
/**
 * Prints a warning message to the console.
 * 
 * @param warningMessage The warning message to be printed.
 */
void printWarning(char* warningMessage) {
    fprintf(stderr, "%sWarning: %s%s\n", YELLOW, warningMessage, RESET);
}

/**
 * Prints a warning message to the console with a line number.
 * 
 * @param warningMessage The warning message to be printed.
 * @param lineNumber The line number where the warning occurred.
 */
void printWarningAtLine(char* warningMessage, int lineNumber) {
    fprintf(stderr, "%sWarning: %s at line %d%s\n", YELLOW, warningMessage, lineNumber, RESET);
}

/**
 * Prints the usage of the program to the console.
 * 
 * @param programName The name of the program.
 */
void printUsage(char* programName) {
    fprintf(stderr, "%sUsage: %s <input_file.lmc> <output_exe> (optional) [-c]%s\n", RED, programName, RESET);
    fprintf(stderr, "%sAlternate Usage: %s -help%s\n", RED, programName, RESET);
    exit(EXIT_FAILURE);
}

/**
 * Prints the usage of the program to the console with help information.
 * 
 * @param programName The name of the program.
 */
void printUsageWithHelp(char* programName){
    fprintf(stderr, "The lemonicomp compiler is a compiler for the Lemonic programming language.\n");
    fprintf(stderr, "Usage: %s <input_file.lmc> <output_exe> (optional) [-c]\n", programName);
    fprintf(stderr, "Alternate Usage: %s -help\n", programName);
    exit(EXIT_SUCCESS);
}
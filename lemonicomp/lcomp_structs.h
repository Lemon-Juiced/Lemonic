#pragma once
#include <stdbool.h>

typedef struct {
    // Data Members
    int initialNumberOfArgs; // The initial number of arguments
    char *inputFile; // The input file name
    char *outputFile; // The output file name
    bool keepCFile; // Flag to keep the C file after compilation
} ProgamInfo;

typedef struct {
    char *value; // The value (contents) of the token
    char *type; // The type of the token
    int line; // The line number where the token was found
} Token;
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
    char *name; // The name of the token
    char *value; // The value (contents) of the token
    int type; // The type of the token
} Token;
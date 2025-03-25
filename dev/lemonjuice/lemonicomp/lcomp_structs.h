#pragma once
#include <stdbool.h>

typedef struct {
    // Data Members
    int initialNumberOfArgs; // The initial number of arguments
    char *inputFile; // The input file name
    char *outputFile; // The output file name
    bool keepCFile; // Flag to keep the C file after compilation
} ProgamInfo;
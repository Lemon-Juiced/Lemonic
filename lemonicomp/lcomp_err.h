#pragma once
#include <stdio.h>
#include <stdlib.h>

extern char RED[]; // Red color for error messages
extern char YELLOW[]; // Yellow color for warnings
extern char RESET[]; // Reset color

void printError(char* errorMessage);
void printErrorAtLine(char* errorMessage, int lineNumber);
void printWarning(char* warningMessage);
void printWarningAtLine(char* warningMessage, int lineNumber);
void printUsage(char* programName);
void printUsageWithHelp(char* programName);
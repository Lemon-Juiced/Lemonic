#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "LString.h"

/**
 * Various print functions aside from the standard printf.
 */

// Function Protoypes
void print(char* str);
void println(char* str);
void printn();
void printS(LString* str);
void printSln(LString* str);
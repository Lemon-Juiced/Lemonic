#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
 * The Interop class provides utilities for interoperation between Lemonic and selected languages.
 * The extent of this interoperation is mostly running programs in the selected languages and passing data between them.
 * 
 * The class contains the following functions:
 * - runC: Runs a C program and returns the output as a string.
 *         This C program can be a file or a string.
 * - runShell: Runs a shell command and returns the output as a string.
 *             This shell command can be a file or a string.
 */
class Interop {
public:
    // Function Prototypes
    static string runC(bool isFile, string input);
    static string runShell(bool isFile, string input);
};
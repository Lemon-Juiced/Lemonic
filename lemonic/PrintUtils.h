#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
 * The PrintUtils class provides utility functions for printing, not only in general, but also for strings.
 * 
 * The class contains the following functions:
 * - print: Prints a string to the console.
 * - printn: Prints a newline character to the console.
 * - println: Prints a string to the console followed by a newline character.
 * - printf: Prints a formatted string to the console.
 * - printfn: Prints a formatted string to the console followed by a newline character.
 */
class PrintUtils {
public:
    // Function Prototypes
    static void print(string str);
    static void printn();
    static void println(string str);
    static void printf(const char* format, ...);
    static void printfn(const char* format, ...);
};
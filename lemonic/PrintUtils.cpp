#include "PrintUtils.h"
#include <cstdarg>
#include <iostream>
#include <string>

/**
 * Prints a string to the console.
 * 
 * @param str The string to be printed.
 */
void PrintUtils::print(string str){
    cout << str;
}

/**
 * Prints a newline character to the console.
 */
void PrintUtils::printn(){
    cout << endl;
}


/**
 * Prints a string to the console followed by a newline character.
 * 
 * @param str The string to be printed.
 */
void PrintUtils::println(string str){
    PrintUtils::print(str);
    PrintUtils::printn(); // Print a newline character
}

/**
 * Prints a formatted string to the console.
 * 
 * @param format The format string.
 * @param ... The values to be formatted and printed.
 */
void PrintUtils::printf(const char* format, ...){
    va_list args;
    va_start(args, format);
    vprintf(format, args); // Print the formatted string
    va_end(args);
}

/**
 * Prints a formatted string to the console followed by a newline character.
 * 
 * @param format The format string.
 * @param ... The values to be formatted and printed.
 */
void PrintUtils::printfn(const char* format, ...){
    va_list args;
    va_start(args, format);
    vprintf(format, args); // Print the formatted string
    va_end(args);
    PrintUtils::printn(); // Print a newline character
}
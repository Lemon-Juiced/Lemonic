#include "lcomp_translator.h"

/**
 * Translate a string representing a keyword in Lemonic to its C equivalent.
 * 
 * @param inputStr The string to be translated.
 * @return A pointer to the translated string.
 */
char* translate(char* inputStr){
    if (strcmp(inputStr, "int16") == 0) return "short";
    if (strcmp(inputStr, "uint16") == 0) return "unsigned short";
    if (strcmp(inputStr, "int32") == 0) return "int";
    if (strcmp(inputStr, "uint32") == 0) return "unsigned";
    if (strcmp(inputStr, "int64") == 0) return "long";
    if (strcmp(inputStr, "uint64") == 0) return "unsigned long";
    else return inputStr; // Return the original string if no translation is found
}
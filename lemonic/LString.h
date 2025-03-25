#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * The LString "class" is a String class that can store a string of characters.
 * The class is implemented as a struct that contains a few fields:
 * - str: A pointer to the string of characters.
 * - size: The size of the string.
 * 
 * The class also contains a few functions to manipulate the string:
 * - newString: Creates a new LString with a given string.
 * - getString: Returns the string.
 * - getSize: Returns the size of the string.
 * - getCharAt: Returns the character at a given index.
 * - setString: Sets the string to a new string.
 * - setCharAt: Sets the character at a given index.
 * - substring: Returns a substring of the string.
 * - substringInPlace: Returns a substring of the string in place.
 * - firstOccurrence: Returns the first occurrence of a character in the string.
 * - lastOccurrence: Returns the last occurrence of a character in the string.
 * - copy: Copies the string to a new string.
 * - concat: Concatenates two strings.
 * - equals: Compares the current string with another string for equality.
 * - equalsIgnoreCase: Compares the current string with another string for equality, ignoring case.
 * - toUpperCase: Converts the string to uppercase.
 * - toLowerCase: Converts the string to lowercase.
 * - reverse: Reverses the string.
 */
typedef struct {
    // Data Members
    char* str;
    int size;

    // Member Functions
    char* (*getString)(void* self);
    int (*getSize)(void* self);
    char (*getCharAt)(void* self, int index);
    void (*setString)(void* self, const char* str);
    void (*setCharAt)(void* self, int index, char c);
    void (*substringInPlace)(void* self, int start, int end);
    int (*firstOccurrence)(void* self, char c);
    int (*lastOccurrence)(void* self, char c);
    void (*copy)(void* self, const char* str);
    void (*concat)(void* self, const char* str1, const char* str2);
    void (*toUpperCase)(void* self);
    void (*toLowerCase)(void* self);
    void (*reverse)(void* self);
} LString;

// Function Prototypes
LString* newString(const char* str);
char* getString(void* self);
int getSize(void* self);
char getCharAt(void* self, int index);
void setString(void* self, const char* str);
void setCharAt(void* self, int index, char c);
LString* substring(void* self, int start, int end);
void substringInPlace(void* self, int start, int end);
int firstOccurrence(void* self, char c);
int lastOccurrence(void* self, char c);
void copy(void* self, const char* str);
void concat(void* self, const char* str1, const char* str2);
int equals(void* self, LString* otherString);
int equalsIgnoreCase(void* self, LString* otherString);
void toUpperCase(void* self);
void toLowerCase(void* self);
void reverse(void* self);
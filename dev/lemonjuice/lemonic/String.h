#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * The String "class" is a set-sized character array that can store any text data.abort
 * The class is implemented as a struct that contains a few fields:
 * - data: A pointer to the array of characters that store the text data.
 * - size: The number of characters currently stored in the array.
 * 
 * The class also contains a few functions to manipulate the array:
 * - createString: Creates a new String with a given size.
 * - newString: Creates a new String with default size.
 * - destroyString: Frees the memory used by the String.
 * - append: Appends a character to the end of the String.
 * - getSize: Returns the number of characters in the String.
 */
typedef struct {
    // Data Members
    char* data;
    int size;

    // Member Functions
    void (*append)(void* self, char c);
    int (*getSize)(void* self);
    int (*firstOccurrence)(void* self, char c);
    int (*lastOccurrence)(void* self, char c);
    String* (*substring)(void* self, int start, int end);
    String* (*split) (void* self, int index, bool front); 
    String* (*copy) (void* self);
} String;

// Function Prototypes
String* createString(char* data);
String* newString();
void destroyString(void* self);
void append(void* self, char c);
int getSize(void* self);
int firstOccurrence(void* self, char c);
int lastOccurrence(void* self, char c);
String* substring(void* self, int start, int end);
String* split(void* self, int index, bool front);
String* copy(void* self);
#include "LString.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Creates a new LString with a given string.
 * 
 * @param str The string to be stored in the LString.
 * @return A pointer to the newly created LString.
 */
LString* newString(const char* str) {
    LString* lstr = (LString*)malloc(sizeof(LString));
    lstr->size = strlen(str);
    lstr->str = (char*)malloc((lstr->size + 1) * sizeof(char));
    strcpy(lstr->str, str);

    lstr->getString = getString;
    lstr->getSize = getSize;
    lstr->getCharAt = getCharAt;
    lstr->setString = setString;
    lstr->setCharAt = setCharAt;
    lstr->firstOccurrence = firstOccurrence;
    lstr->lastOccurrence = lastOccurrence;
    lstr->copy = copy;
    lstr->concat = concat;
    lstr->toUpperCase = toUpperCase;
    lstr->toLowerCase = toLowerCase;
    lstr->reverse = reverse;

    return lstr;
}

/**
 * Returns the string stored in the LString.
 * 
 * @param self A pointer to the LString.
 * @return The string stored in the LString.
 */
char* getString(void* self) {
    LString* lstr = (LString*)self;
    return lstr->str;
}

/**
 * Returns the size of the string stored in the LString.
 * 
 * @param self A pointer to the LString.
 * @return The size of the string stored in the LString.
 */
int getSize(void* self) {
    LString* lstr = (LString*)self;
    return lstr->size;
}

/**
 * Returns the character at a given index in the string stored in the LString.
 * 
 * @param self A pointer to the LString.
 * @param index The index of the character to be retrieved.
 * @return The character at the given index.
 */
char getCharAt(void* self, int index) {
    LString* lstr = (LString*)self;
    if (index < 0 || index >= lstr->size) {
        printf("Error: Index out of bounds\n");
        return '\0'; // Return null character if index is out of bounds
    }
    return lstr->str[index];
}

/**
 * Sets the string stored in the LString to a new string.
 * 
 * @param self A pointer to the LString.
 * @param str The new string to be set.
 */
void setString(void* self, const char* str) {
    LString* lstr = (LString*)self;
    free(lstr->str); // Free the old string
    lstr->size = strlen(str);
    lstr->str = (char*)malloc((lstr->size + 1) * sizeof(char));
    strcpy(lstr->str, str);
}

/**
 * Sets the character at a given index in the string stored in the LString.
 * 
 * @param self A pointer to the LString.
 * @param index The index of the character to be set.
 * @param c The new character to be set.
 */
void setCharAt(void* self, int index, char c) {
    LString* lstr = (LString*)self;
    if (index < 0 || index >= lstr->size) {
        printf("Error: Index out of bounds\n");
        return;
    }
    lstr->str[index] = c;
}

/**
 * Returns a substring of the string stored in the LString.
 * 
 * @param self A pointer to the LString.
 * @param start The starting index of the substring.
 * @param end The ending index of the substring.
 * @return A pointer to the new LString containing the substring.
 */
LString* substring(void* self, int start, int end) {
    LString* lstr = (LString*)self;
    if (start < 0 || end > lstr->size || start >= end) {
        printf("Error: Invalid substring indices\n");
        return NULL; // Return NULL if indices are invalid
    }
    char* substr = (char*)malloc((end - start + 1) * sizeof(char));
    strncpy(substr, lstr->str + start, end - start);
    substr[end - start] = '\0'; // Null-terminate the substring
    return newString(substr); // Create a new LString for the substring
}

/**
 * Returns a substring of the string stored in the LString in place.
 * 
 * @param self A pointer to the LString.
 * @param start The starting index of the substring.
 * @param end The ending index of the substring.
 * @return A pointer to the new LString containing the substring.
 */
void substringInPlace(void* self, int start, int end) {
    LString* lstr = (LString*)self;
    if (start < 0 || end > lstr->size || start >= end) {
        printf("Error: Invalid substring indices\n");
        return; // Return NULL if indices are invalid
    }
    char* substr = (char*)malloc((end - start + 1) * sizeof(char));
    strncpy(substr, lstr->str + start, end - start);
    substr[end - start] = '\0'; // Null-terminate the substring
    free(lstr->str); // Free the old string
    lstr->str = substr; // Set the new string
    lstr->size = end - start; // Update the size
}

/**
 * Returns the first occurrence of a character in the string stored in the LString.
 * 
 * @param self A pointer to the LString.
 * @param c The character to be searched for.
 * @return The index of the first occurrence of the character, or -1 if not found.
 */
int firstOccurrence(void* self, char c) {
    LString* lstr = (LString*)self;
    for (int i = 0; i < lstr->size; i++) {
        if (lstr->str[i] == c) {
            return i; // Return the index of the first occurrence
        }
    }
    return -1; // Return -1 if not found
}

/**
 * Returns the last occurrence of a character in the string stored in the LString.
 * 
 * @param self A pointer to the LString.
 * @param c The character to be searched for.
 * @return The index of the last occurrence of the character, or -1 if not found.
 */
int lastOccurrence(void* self, char c) {
    LString* lstr = (LString*)self;
    for (int i = lstr->size - 1; i >= 0; i--) {
        if (lstr->str[i] == c) {
            return i; // Return the index of the last occurrence
        }
    }
    return -1; // Return -1 if not found
}

/**
 * Copies the string stored in the LString to a new string.
 * 
 * @param self A pointer to the LString.
 * @param str The new string to be copied.
 */
void copy(void* self, const char* str) {
    LString* lstr = (LString*)self;
    free(lstr->str); // Free the old string
    lstr->size = strlen(str);
    lstr->str = (char*)malloc((lstr->size + 1) * sizeof(char));
    strcpy(lstr->str, str);
}

/**
 * Concatenates two strings and stores the result in the LString.
 * 
 * @param self A pointer to the LString.
 * @param str1 The first string to be concatenated.
 * @param str2 The second string to be concatenated.
 */
void concat(void* self, const char* str1, const char* str2) {
    LString* lstr = (LString*)self;
    free(lstr->str); // Free the old string
    lstr->size = strlen(str1) + strlen(str2);
    lstr->str = (char*)malloc((lstr->size + 1) * sizeof(char));
    strcpy(lstr->str, str1); // Copy the first string
    strcat(lstr->str, str2); // Concatenate the second string
}

/**
 * Compares the current string with another string for equality.
 * 
 * @param self A pointer to the LString.
 * @param otherString A pointer to the other LString to be compared.
 * @return 1 if equal, 0 if not equal.
 */
int equals(void* self, LString* otherString) {
    LString* lstr = (LString*)self;
    if (lstr->size != otherString->size) {
        return 0; // Not equal if sizes are different
    }
    return strcmp(lstr->str, otherString->str) == 0; // Compare the strings
}

/**
 * Compares the current string with another string for equality, ignoring case.
 * 
 * @param self A pointer to the LString.
 * @param otherString A pointer to the other LString to be compared.
 * @return 1 if equal, 0 if not equal.
 */
int equalsIgnoreCase(void* self, LString* otherString) {
    LString* lstr = (LString*)self;
    if (lstr->size != otherString->size) {
        return 0; // Not equal if sizes are different
    }
    for (int i = 0; i < lstr->size; i++) {
        if (tolower(lstr->str[i]) != tolower(otherString->str[i])) {
            return 0; // Not equal if characters differ
        }
    }
    return 1; // Equal if all characters match ignoring case
}

/**
 * Converts the string stored in the LString to uppercase.
 * 
 * @param self A pointer to the LString.
 */
void toUpperCase(void* self) {
    LString* lstr = (LString*)self;
    for (int i = 0; i < lstr->size; i++) {
        lstr->str[i] = toupper(lstr->str[i]); // Convert each character to uppercase
    }
}

/**
 * Converts the string stored in the LString to lowercase.
 * 
 * @param self A pointer to the LString.
 */
void toLowerCase(void* self) {
    LString* lstr = (LString*)self;
    for (int i = 0; i < lstr->size; i++) {
        lstr->str[i] = tolower(lstr->str[i]); // Convert each character to lowercase
    }
}

/**
 * Reverses the string stored in the LString.
 * 
 * @param self A pointer to the LString.
 */
void reverse(void* self) {
    LString* lstr = (LString*)self;
    for (int i = 0; i < lstr->size / 2; i++) {
        char temp = lstr->str[i]; // Swap characters
        lstr->str[i] = lstr->str[lstr->size - i - 1];
        lstr->str[lstr->size - i - 1] = temp;
    }
}
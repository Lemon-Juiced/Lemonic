#include "String.h"

/**
 * Creates a new String with a given size.
 * 
 * @param data The initial data of the String.
 * @return A pointer to the newly created String.
 */
String* createString(char* data) {
    String* str = (String*)malloc(sizeof(String));
    str->data = data;
    str->size = 0;
    while (data[str->size] != '\0') {
        str->size++;
    }

    str->append = append;
    str->getSize = getSize;

    return str;
}

/**
 * Creates a new String with default size.
 * Default size is 10.
 * 
 * @return A pointer to the newly created String.
 */
String* newString() {
    return createString("");
}

/**
 * Frees the memory used by the String.
 * 
 * @param self A pointer to the String to be destroyed.
 */
void destroyString(void* self) {
    String* str = (String*)self;
    free(str->data);
    free(str);
}

/**
 * Appends a character to the end of the String.
 * 
 * @param self A pointer to the String.
 * @param c The character to be appended.
 */
void append(void* self, char c) {
    String* str = (String*)self;
    str->data = (char*)realloc(str->data, (str->size + 2) * sizeof(char));
    str->data[str->size] = c;
    str->data[str->size + 1] = '\0';
    str->size++;
}

/**
 * Returns the number of characters in the String.
 * 
 * @param self A pointer to the String.
 * @return The number of characters in the String.
 */
int getSize(void* self) {
    String* str = (String*)self;
    return str->size;
}

/**
 * Finds the first occurrence of a character in the String.
 * 
 * @param self A pointer to the String.
 * @param c The character to be found.
 * @return The index of the first occurrence of the character, or -1 if not found.
 */
int firstOccurrence(void* self, char c) {
    String* str = (String*)self;
    for (int i = 0; i < str->size; i++) {
        if (str->data[i] == c) {
            return i;
        }
    }
    return -1;
}

/**
 * Finds the last occurrence of a character in the String.
 * 
 * @param self A pointer to the String.
 * @param c The character to be found.
 * @return The index of the last occurrence of the character, or -1 if not found.
 */
int lastOccurrence(void* self, char c) {
    String* str = (String*)self;
    for (int i = str->size - 1; i >= 0; i--) {
        if (str->data[i] == c) {
            return i;
        }
    }
    return -1;
}

/**
 * Creates a substring of the String from start to end index.
 * 
 * @param self A pointer to the String.
 * @param start The starting index of the substring.
 * @param end The ending index of the substring.
 * @return A pointer to the newly created substring.
 */
String* substring(void* self, int start, int end) {
    String* str = (String*)self;
    if (start < 0 || end > str->size || start >= end) {
        return NULL; // Invalid indices
    }

    String* subStr = createString("");
    for (int i = start; i < end; i++) {
        subStr->append(subStr, str->data[i]);
    }
    return subStr;
}

/**
 * Splits the String based on an index and returns the front or back part.
 * 
 * @param self A pointer to the String.
 * @param index The index to split the String.
 * @param front If true, returns the front part; otherwise, returns the back part.
 * @return A pointer to the newly created split String.
 */
String* split(void* self, int index, bool front) {
    String* str = (String*)self;
    if (index < 0 || index > str->size) {
        return NULL; // Invalid index
    }

    String* splitStr = createString("");
    if (front) {
        for (int i = 0; i < index; i++) {
            splitStr->append(splitStr, str->data[i]);
        }
    } else {
        for (int i = index; i < str->size; i++) {
            splitStr->append(splitStr, str->data[i]);
        }
    }
    return splitStr;
}

/**
 * Creates a copy of the String.
 * 
 * @param self A pointer to the String.
 * @return A pointer to the newly created copy of the String.
 */
String* copy(void* self) {
    String* str = (String*)self;
    String* newStr = createString("");
    for (int i = 0; i < str->size; i++) {
        newStr->append(newStr, str->data[i]);
    }
    return newStr;
}
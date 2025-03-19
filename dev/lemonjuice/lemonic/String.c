#include "String.h"
#include <stdio.h>
#include <stdlib.h>

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
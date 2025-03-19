#include "../../String.h"
#include <stdio.h>
#include <stdlib.h>

// Custom string comparison function
int compareStrings(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

void testCreateString() {
    String* str = createString("Hello");
    if (compareStrings(str->data, "Hello") == 0 && str->size == 5) {
        printf("testCreateString passed\n");
    } else {
        printf("testCreateString failed\n");
    }
    destroyString(str);
}

void testNewString() {
    String* str = newString();
    if (compareStrings(str->data, "") == 0 && str->size == 0) {
        printf("testNewString passed\n");
    } else {
        printf("testNewString failed\n");
    }
    destroyString(str);
}

void testAppend() {
    String* str = createString("Hello");
    str->append(str, '!');
    if (compareStrings(str->data, "Hello!") == 0 && str->size == 6) {
        printf("testAppend passed\n");
    } else {
        printf("testAppend failed\n");
    }
    destroyString(str);
}

void testGetSize() {
    String* str = createString("Hello");
    if (str->getSize(str) == 5) {
        printf("testGetSize passed\n");
    } else {
        printf("testGetSize failed\n");
    }
    destroyString(str);
}

int main() {
    testCreateString();
    testNewString();
    testAppend();
    testGetSize();
    return 0;
}
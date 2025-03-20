#include <stdio.h>
#include "../../LString.h"

int main() {
    // Create a new LString
    LString *str = newString("Hello, World!");

    // Print the string and its size
    printf("String: %s\n", str->getString(str));
    printf("Size: %d\n", str->getSize(str));

    // Get and print a character at a specific index
    printf("Character at index 7: %c\n", str->getCharAt(str, 7));

    // Set a new string
    str->setString(str, "Goodbye, World!");
    printf("New String: %s\n", str->getString(str));

    // Set a character at a specific index
    str->setCharAt(str, 8, 'X');
    printf("String after setting character: %s\n", str->getString(str));

    // Get a substring
    LString *substr = substring(str, 8, 13);
    printf("Substring: %s\n", substr->getString(substr));

    // Find the first and last occurrence of a character
    printf("First occurrence of 'o': %d\n", str->firstOccurrence(str, 'o'));
    printf("Last occurrence of 'o': %d\n", str->lastOccurrence(str, 'o'));

    // Convert to uppercase and lowercase
    str->toUpperCase(str);
    printf("Uppercase: %s\n", str->getString(str));
    str->toLowerCase(str);
    printf("Lowercase: %s\n", str->getString(str));

    // Reverse the string
    str->reverse(str);
    printf("Reversed: %s\n", str->getString(str));

    // Clean up
    free(str->str);
    free(str);
    free(substr->str);
    free(substr);

    return 0;
}
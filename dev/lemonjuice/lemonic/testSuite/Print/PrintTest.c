#include <stdio.h>
#include "../../LString.h"
#include "../../Print.h"

int main() {
    // Test print and println with a regular string
    char* testStr = "Hello, World!";
    print(testStr);
    printn(); // Test Print a newline character
    println(testStr);

    // Create a new LString
    LString *lstr = newString("Hello, LString!");

    // Test printS and printSln with LString
    printS(lstr);
    printn(); // Test Print a newline character
    printSln(lstr);

    // Clean up
    free(lstr->str);
    free(lstr);

    return 0;
}
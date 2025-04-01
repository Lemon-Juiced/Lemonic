#include "../../PrintUtils.h"

int main() {
    // Test print and println with a regular string
    string testStr = "Hello, World!";
    PrintUtils::print(testStr);
    PrintUtils::printn(); // Print a newline character
    PrintUtils::println(testStr);

    // Test printf and printfn with formatted strings
    PrintUtils::printf("Formatted string: %d, %f, %s", 42, 3.14, "example");
    PrintUtils::printn(); // Print a newline character
    PrintUtils::printfn("Formatted string with newline: %d, %f, %s", 42, 3.14, "example");

    return 0;
}
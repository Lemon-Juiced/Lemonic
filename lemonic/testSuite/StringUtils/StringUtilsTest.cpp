#include <iostream>
#include "../../StringUtils.h"

using namespace std;

int main() {
    // Test getSize
    string str = "Hello, World!";
    cout << "String: " << str << endl;
    cout << "Size: " << StringUtils::getSize(str) << endl;

    // Test getCharAt
    cout << "Character at index 7: " << StringUtils::getCharAt(str, 7) << endl;

    // Test setCharAt
    StringUtils::setCharAt(str, 7, 'X');
    cout << "String after setting character: " << str << endl;

    // Test substring
    string substr = StringUtils::substring(str, 7, 12);
    cout << "Substring: " << substr << endl;

    // Test substringInPlace
    StringUtils::substringInPlace(str, 7, 12);
    cout << "String after in-place substring: " << str << endl;

    // Reset string for further tests
    str = "Hello, World!";

    // Test firstOccurrence
    cout << "First occurrence of 'o': " << StringUtils::firstOccurrence(str, 'o') << endl;

    // Test lastOccurrence
    cout << "Last occurrence of 'o': " << StringUtils::lastOccurrence(str, 'o') << endl;

    // Test toUpperCase
    string upperStr = StringUtils::toUpperCase(str);
    cout << "Uppercase: " << upperStr << endl;

    // Test toLowerCase
    string lowerStr = StringUtils::toLowerCase(str);
    cout << "Lowercase: " << lowerStr << endl;

    // Test reverse
    string reversedStr = StringUtils::reverse(str);
    cout << "Reversed: " << reversedStr << endl;

    // Test equals
    cout << "Equals 'Hello, World!': " << (StringUtils::equals(str, "Hello, World!") ? "true" : "false") << endl;

    // Test equalsIgnoreCase
    cout << "EqualsIgnoreCase 'hello, world!': " << (StringUtils::equalsIgnoreCase(str, "hello, world!") ? "true" : "false") << endl;

    // Test concat
    string concatenatedStr = StringUtils::concat(str, " Goodbye!");
    cout << "Concatenated: " << concatenatedStr << endl;

    return 0;
}
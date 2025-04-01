#pragma once
#include <string>

using namespace std;

/**
 * The StringUtils class is a utility class that provides various string manipulation functions.
 * 
 * The class contains the following functions:
 * - getSize: Returns the size of a string.
 * - getCharAt: Returns the character at a given index in a string.
 * - setCharAt: Sets the character at a given index in a string.
 * - substring: Returns a substring of a string.
 * - substringInPlace: Returns a substring of a string in place.
 * - firstOccurrence: Returns the first occurrence of a character in a string.
 * - lastOccurrence: Returns the last occurrence of a character in a string.
 * - copy: Copies a string to a new string.
 * - concat: Concatenates two strings.
 * - equals: Compares two strings for equality.
 * - equalsIgnoreCase: Compares two strings for equality, ignoring case.
 * - toUpperCase: Converts a string to uppercase.
 * - toLowerCase: Converts a string to lowercase.
 * * - reverse: Reverses a string.
 */
class StringUtils {
public:
    // Function Prototypes
    static int getSize(string str);
    static char getCharAt(string str, int index);
    static void setCharAt(string& str, int index, char c);
    static string substring(string str, int start, int end);
    static void substringInPlace(string& str, int start, int end);
    static int firstOccurrence(string str, char c);
    static int lastOccurrence(string str, char c);
    static string copy(const string str);
    static string concat(string str1, string str2);
    static string toUpperCase(string str);
    static string toLowerCase(string str);
    static bool equals(string str1, string str2);
    static bool equalsIgnoreCase(string str1, string str2);
    static string reverse(string str);
};

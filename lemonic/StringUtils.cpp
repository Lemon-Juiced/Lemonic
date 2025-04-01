#include "StringUtils.h"
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>

using namespace std;

/**
 * Returns the size of a string.
 * 
 * @param str The string whose size is to be determined.
 * @return The size of the string.
 */
int StringUtils::getSize(string str) {
    return str.length();
}

/**
 * Returns the character at a given index in a string.
 * 
 * @param str The string from which the character is to be retrieved.
 * @param index The index of the character to be retrieved.
 */
char StringUtils::getCharAt(string str, int index) {
    if (index < 0 || index >= getSize(str)) 
        throw out_of_range("Index out of bounds");
    return str[index];
}

/**
 * Sets the character at a given index in a string.
 * 
 * @param str The string in which the character is to be set.
 * @param index The index of the character to be set.
 * @param c The new character to be set.
 */
void StringUtils::setCharAt(string& str, int index, char c){
    if (index < 0 || index >= getSize(str)) 
        throw out_of_range("Index out of bounds");
    str[index] = c;
}

/**
 * Returns a substring of a string.
 * 
 * @param str The string from which the substring is to be extracted.
 * @param start The starting index of the substring.
 * @param end The ending index of the substring.
 * @return The substring.
 */
string StringUtils::substring(string str, int start, int end){
    if (start < 0 || end > getSize(str) || start >= end) 
        throw out_of_range("Invalid substring indices");
    return str.substr(start, end - start);
}

/**
 * Returns a substring of a string in place.
 * 
 * @param str The string in which the substring is to be extracted.
 * @param start The starting index of the substring.
 * @param end The ending index of the substring.
 */
void StringUtils::substringInPlace(string& str, int start, int end){
    if (start < 0 || end > getSize(str) || start >= end) 
        throw out_of_range("Invalid substring indices");
    str = str.substr(start, end - start);
}

/**
 * Returns the first occurrence of a character in a string.
 * 
 * @param str The string in which to search for the character.
 * @param c The character to be searched for.
 * @return The index of the first occurrence of the character, or -1 if not found.
 */
int StringUtils::firstOccurrence(string str, char c){
    size_t pos = str.find(c);
    if (pos != string::npos) return static_cast<int>(pos);
    else return -1;
}

/**
 * Returns the last occurrence of a character in a string.
 * 
 * @param str The string in which to search for the character.
 * @param c The character to be searched for.
 * @return The index of the last occurrence of the character, or -1 if not found.
 */
int StringUtils::lastOccurrence(string str, char c){
    size_t pos = str.rfind(c);
    if (pos != string::npos) return static_cast<int>(pos);
    else return -1;
}

/**
 * Copies a string to a new string.
 * 
 * @param str The string to be copied.
 * @return The copied string.
 */
string StringUtils::copy(const string str){
    return str;
}

/**
 * Concatenates two strings.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return The concatenated string.
 */
string StringUtils::concat(string str1, string str2){
    return str1 + str2;
}

/**
 * Converts a string to uppercase.
 * 
 * @param str The string to be converted.
 * @return The uppercase string.
 */
string StringUtils::toUpperCase(string str){
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

/**
 * Converts a string to lowercase.
 * 
 * @param str The string to be converted.
 * @return The lowercase string.
 */
string StringUtils::toLowerCase(string str){
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

/**
 * Compares two strings for equality.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return true if equal, false if not equal.
 */
bool StringUtils::equals(string str1, string str2){
    return str1 == str2;
}

/**
 * Compares two strings for equality, ignoring case.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return true if equal, false if not equal.
 */
bool StringUtils::equalsIgnoreCase(string str1, string str2){
    return toLowerCase(str1) == toLowerCase(str2);
}

/**
 * Reverses a string.
 * 
 * @param str The string to be reversed.
 * @return The reversed string.
 */
string StringUtils::reverse(string str){
    string result = str;
    std::reverse(result.begin(), result.end());
    return result;
}
# Lemonic C
Lemonic C, or simply Lemonic, is a new derivative of C designed to simplify and enhance the language.

## What is Lemonic?
The name "Lemonic" combines "Lemon" (inspired by the developer) and "Demonic" (reflecting the challenging nature of creating this language). Although the full name is Lemonic C, it is often abbreviated to just Lemonic. 

### History & Original Intent
Initially, the project aimed to be a superset of C, much like C++, but it gradually evolved into a distinct language with its own syntax and semantics. Features absent in C but present in higher-level languages, such as templates in C++, influenced this transformation. Currently, the project includes components written in both C and C++, with Makefiles distributed across the project for building and testing. Moving forward, the focus will remain on these three languages, but alternative tools or languages may be considered if they provide a clear advantage for specific tasks.

## How it Works
Lemonic uses existing C and C++ tools, such as `gcc` and `g++`. When a Lemonic program is compiled, it is first translated into an equivalent C/C++ program, which is then compiled using the standard GNU compilers. The file extension for a Lemonic program is `.lmc` and is compiled via the Lemonic compiler, `lemonicomp`.

## Progress
### Completed
- `ArrayList.cpp`, `ArrayList.h`, and `ArrayListTest.cpp`
  - ArrayList Implementation 
- `StringUtils.cpp`, `StringUtils.h`, and `StringUtilsTest.cpp`
  - String Utilities Implementation
- `PrintUtils.cpp`, `PrintUtils.h`, and `PrintUtilsTest.cpp`
  - Print Function Implementations 

### In Progress
- The Compiler: `lemonicomp.c`
  - Compiler Flags Added: 
    - `-c` Keeps the C file after translation.
    - `-help` Prints Usage Information
  - To Do: Add Translation

### To Do
- Implementations for many features.

## Contribution, Bugs, & Suggestions
If you would like to contribute to this project, please follow these steps:
- To contribute, open a pull request.
- To report a bug, open an issue.
- For suggestions or requests, open an issue.

## Other Resources
Documentation - Not Yet Available  
[Style Guide](https://github.com/Lemon-Juiced/Lemonic/blob/main/StyleGuide.md)  
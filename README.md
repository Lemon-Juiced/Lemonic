# Lemonic C
Lemonic C, or simply Lemonic, is a new derivative of C designed to simplify and enhance the language.

## What is Lemonic?
The name "Lemonic" combines "Lemon" (inspired by the developer) and "Demonic" (reflecting the challenging nature of creating this language). Although the full name is Lemonic C, it is often abbreviated to just Lemonic. The project started as a superset of C, similar to C++, but evolved into a more customized language with its own syntax and semantics.

## How it Works
Lemonic uses existing C and C++ tools, such as `gcc` and `g++`. When a Lemonic program is compiled, it is first translated into an equivalent C/C++ program, which is then compiled using the standard GNU compilers. The file extension for a Lemonic program is `.lmc` and is compiled via the Lemonic compiler, `lemonicomp`.

## Progress
### Completed
- `ArrayList.cpp`, `ArrayList.h`, and `ArrayListTest.cpp`
  - ArrayList Implementation (Uses C++ For Templates)
- `LString.c`, `LString.h`, and `LStringTest.c`
  - String Implementation (Uses C)
  - The syntax should ideally be more similar to other languages, but it functions as is.
- `Print.c`, `Print.h`, and `PrintTest.c`
  - Print Implementations (Uses C)
  - Additional print functions.

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
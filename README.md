# Lemonic C
Lemonic C, or simply Lemonic, is a new derivative of C designed to simplify and enhance the language.

## What is Lemonic?
The name "Lemonic" combines "Lemon" (inspired by the developer) and "Demonic" (reflecting the challenging nature of creating this language). Although the full name is Lemonic C, it is often abbreviated to just Lemonic. The project started as a superset of C, similar to C++, but evolved into a more customized language with its own syntax and semantics.

## How it Works
Lemonic uses existing C tools, such as `gcc`. When a Lemonic program is compiled, it is first translated into an equivalent C program, which is then compiled using a standard C compiler. The file extension for a Lemonic program is `.lmc` and is compiled via the Lemonic compiler, `lemonicomp`.

## Progress
### Completed
- `ArrayList.c`, `ArrayList.h`, and `ArrayListTest.c`
  - ArrayList Implementation
  - The syntax should ideally be more similar to other languages, but it functions as is.
- `LString.c`, `LString.h`, and `LStringTest.c`
  - String Implementation
  - The syntax should ideally be more similar to other languages, but it functions as is.
- `Print.c`, `Print.h`, and `PrintTest.c`
  - Additional print functions.

### In Progress
- The Compiler: `lemonicomp.c`
  - Compiler Flags Added: '-c' keeps the C file after translation.
  - To Do: Add Translation

### To Do
- Implementations for many features.

## Contribution, Bugs, & Suggestions
If you would like to contribute to this project, please follow these steps:
- To contribute, open a pull request.
- To report a bug, open an issue.
- For suggestions or requests, open an issue.

## Style Guide
Lemonic code has a simple and quick style guide:
- Use `lowerCamelCase` for variable and function names.
- Use `UpperCamelCase` for class and type names.
- Use braces `{}` for all control structures.

If discrepancies arise and need to be addressed, they will be added to the style guide.
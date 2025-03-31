#include "lcomp_tokenizer.h"

#define LINE_BUFFER_SIZE 1024 // A reasonable buffer size for a line of text

/**
 * Reads a line from the file and tokenizes it.
 * 
 * @param line The line to tokenize.
 * @param tokens A pointer to the array of tokens.
 * @param size A pointer to the current size of the tokens array.
 * @param capacity A pointer to the current capacity of the tokens array.
 * @param line_number The line number of the current line.
 * @return 0 on success, -1 on failure.
 */
int tokenizeLine(char* line, Token** tokens, unsigned long* size, unsigned long* capacity, int line_number) {
    char* token = strtok(line, " \n"); // Tokenize the line using space and newline as delimiters (needs to be changed to a more complex tokenizer)
    while (token != NULL) {
        // Resize the tokens array if needed
        if (*size >= *capacity) {
            *capacity *= 2;
            *tokens = (Token*)realloc(*tokens, sizeof(Token) * (*capacity));
            if (*tokens == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                return -1;
            }
        }

        // Create a new token and add it to the array
        (*tokens)[*size] = createToken(token, "TOKEN", line_number); // Replace "TOKEN" with actual logic
        (*size)++;

        token = strtok(NULL, " \n");
    }
    return 0;
}

/**
 * Parses the input file and returns an array of tokens.
 * 
 * @param input_file The input file to be parsed.
 * @param token_count A pointer to an unsigned long variable to store the number of tokens found.
 * @return A pointer to an array of tokens.
 */
Token* parse(char* input_file, unsigned long* token_count) {
    FILE* file = fopen(input_file, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", input_file);
        return NULL;
    }

    Token* tokens = (Token*)malloc(sizeof(Token) * 10);
    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    unsigned long capacity = 10;
    unsigned long size = 0;
    char* line = (char*)malloc(LINE_BUFFER_SIZE); // Allocate a buffer for reading lines
    if (line == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(tokens);
        fclose(file);
        return NULL;
    }

    int line_number = 0; // Initialize line number
    while (fgets(line, LINE_BUFFER_SIZE, file) != NULL) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = 0;
        line_number++; // Increment line number
        if (tokenizeLine(line, &tokens, &size, &capacity, line_number) == -1) {
            free(tokens);
            free(line);
            fclose(file);
            return NULL;
        }
    }

    free(line);
    fclose(file);

    *token_count = size;
    return tokens;
}

/**
 * Creates a new token with the given value, type, and line number.
 * 
 * @param value The value of the token.
 * @param type The type of the token.
 * @param line The line number where the token was found.
 * @return The newly created token.
 */
Token createToken(char* value, char* type, int line) {
    Token token;
    token.value = (char*)malloc(strlen(value) + 1);
    if (token.value == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return token;
    }
    strcpy(token.value, value);

    token.type = (char*)malloc(strlen(type) + 1);
    if (token.type == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(token.value);
        return token;
    }
    strcpy(token.type, type);

    token.line = line;
    return token;
}
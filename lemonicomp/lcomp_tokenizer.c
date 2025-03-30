#include "lcomp_tokenizer.h" 

/**
 * Parses the input string and returns an array of tokens.
 * 
 * @param input_file The input file to be parsed.
 * @param token_count A pointer to an unsigned long variable to store the number of tokens found.
 *                    Since this is a pointer, the value will be updated in the calling function.
 *                    As such this value is mutated by this function.
 * @return A pointer to an array of tokens.
 */
Token* parse(char* input_file, unsigned long* token_count){
    // Since the input is a file, we need to read the file line by line.
    // Open the input file for reading
    FILE* file = fopen(input_file, "r"); // Open the file in read mode
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", input_file);
        return NULL; // Return NULL if the file cannot be opened
    }
    
    // Convert the contents of input_file (a file) to a input (a string)
    // Read the file line by line and store it in a string
    char* input = (char*)malloc(1024 * sizeof(char)); // Allocate memory for the input string
    if (input == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file); // Close the file before returning
        return NULL; // Return NULL if memory allocation fails
    }
    size_t len = 0; // Length of the input string
    while (fgets(input + len, 1024 - len, file) != NULL) { // Read the file line by line
        len += strlen(input + len); // Update the length of the input string
        if (len >= 1024) { // Check if the input string is too long
            fprintf(stderr, "Input string is too long\n");
            free(input); // Free the allocated memory before returning
            fclose(file); // Close the file before returning
            return NULL; // Return NULL if the input string is too long
        }
    }
    fclose(file); // Close the file after reading

    // Set the initial number of tokens to 0
    *token_count = 0; // Set to 0 to start with

    // Allocate memory for the tokens array
    Token* tokens = (Token*)malloc(sizeof(Token) * 10); // Start with 10 tokens
    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL; // Return NULL if memory allocation fails
    }

    unsigned long capacity = 10; // Initial capacity of the tokens array
    unsigned long size = 0; // Current size of the tokens array

    // This is the main loop that will parse the input string
    char* token = strtok(input, " \n"); // Tokenize the input string using space and newline as delimiters (this is naive and should be improved)
    while (token != NULL) {
        // Check if we need to resize the tokens array
        if (size >= capacity) {
            capacity *= 2; // Double the capacity
            tokens = (Token*)realloc(tokens, sizeof(Token) * capacity); // Resize the array
            if (tokens == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                return NULL; // Return NULL if memory reallocation fails
            }
        }

        // Create a new token and add it to the tokens array
        tokens[size] = createToken(token, "TOKEN", 1); // To Do: Replace "TOKEN" with actual type. Requires the tokens to be fully separated first.
        size++; // Increment the size of the tokens array

        token = strtok(NULL, " \n"); // Get the next token
    }
    
    // Finally, return the tokens array and update the token count
    *token_count = size; // Update the token count
    return tokens; // Return the tokens array
}

/**
 * Creates a new token with the given value, type, and line number.
 * 
 * @param value The value of the token.
 * @param type The type of the token.
 * @param line The line number where the token was found.
 * @return The newly created token.
 */
Token createToken(char* value, char* type, int line){
    Token token;
    token.value = (char*)malloc(strlen(value) + 1); // Allocate memory for the value
    if (token.value == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return token; // Return an empty token if memory allocation fails
    }
    strcpy(token.value, value); // Copy the value to the token
    token.type = (char*)malloc(strlen(type) + 1); // Allocate memory for the type
    if (token.type == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(token.value); // Free the previously allocated memory for value
        return token; // Return an empty token if memory allocation fails
    }
    strcpy(token.type, type); // Copy the type to the token
    token.line = line; // Set the line number

    return token; // Return the newly created token
}
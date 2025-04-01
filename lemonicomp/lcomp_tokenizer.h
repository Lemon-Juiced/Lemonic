#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcomp_err.h"
#include "lcomp_structs.h"

int tokenizeLine(char* line, Token** tokens, unsigned long* size, unsigned long* capacity, int line_number );
Token* parse(char* input, unsigned long* token_count);
Token createToken(char* value, char* type, int line);
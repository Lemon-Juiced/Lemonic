#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcomp_structs.h"

Token* parse(char* input, unsigned long* token_count);
Token createToken(char* value, char* type, int line);
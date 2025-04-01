# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Source files and object files
SRC = lemonicomp.c lcomp_prototypes.c lcomp_tokenizer.c lcomp_err.c
OBJ = $(SRC:.c=.o)

# Target executable
TARGET = lemonicomp

# Default rule
all: $(TARGET) clean_objs

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Pattern rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files after build
clean_objs:
	rm -f $(OBJ)

# Clean rule to remove all build artifacts
clean:
	rm -f $(OBJ) $(TARGET)
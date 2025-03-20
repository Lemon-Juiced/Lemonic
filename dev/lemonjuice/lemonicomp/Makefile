# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Object files
OBJ = lemonicomp.o

# Target executable
TARGET = lemonicomp

# Default rule
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to compile lemonicomp.c
lemonicomp.o: lemonicomp.c
	$(CC) $(CFLAGS) -c lemonicomp.c -o lemonicomp.o

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)
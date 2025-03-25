# Makefile for compiling and linking LString and LStringTest

CC = gcc
CFLAGS = -I../../ -Wall -Wextra -std=c11

# Object files
OBJ = LString.o LStringTest.o

# Target executable
TARGET = LStringTest

# Default rule
all: $(TARGET) clean_objs

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to compile LString.c
LString.o: ../../LString.c
	$(CC) $(CFLAGS) -c ../../LString.c -o LString.o

# Rule to compile LStringTest.c
LStringTest.o: LStringTest.c
	$(CC) $(CFLAGS) -c LStringTest.c -o LStringTest.o

# Rule to clean object files after build
clean_objs:
	rm -f $(OBJ)

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)
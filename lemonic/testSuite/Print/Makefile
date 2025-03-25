# Makefile for compiling and linking Print and PrintTest

CC = gcc
CFLAGS = -I../../ -Wall -Wextra -std=c11

# Object files
OBJ = LString.o Print.o PrintTest.o

# Target executable
TARGET = PrintTest

# Default rule
all: $(TARGET) clean_objs

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to compile LString.c
LString.o: ../../LString.c
	$(CC) $(CFLAGS) -c ../../LString.c -o LString.o

# Rule to compile Print.c
Print.o: ../../Print.c
	$(CC) $(CFLAGS) -c ../../Print.c -o Print.o

# Rule to compile PrintTest.c
PrintTest.o: PrintTest.c
	$(CC) $(CFLAGS) -c PrintTest.c -o PrintTest.o

# Rule to clean object files after build
clean_objs:
	rm -f $(OBJ)

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)
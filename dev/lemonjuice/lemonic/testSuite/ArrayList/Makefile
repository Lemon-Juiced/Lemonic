# Makefile for compiling and linking ArrayList and ArrayListTest

CC = gcc
CFLAGS = -I../../ -Wall -Wextra -std=c11

# Object files
OBJ = ArrayList.o ArrayListTest.o

# Target executable
TARGET = ArrayListTest

# Default rule
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to compile ArrayList.c
ArrayList.o: ../../ArrayList.c
	$(CC) $(CFLAGS) -c ../../ArrayList.c -o ArrayList.o

# Rule to compile ArrayListTest.c
ArrayListTest.o: ArrayListTest.c
	$(CC) $(CFLAGS) -c ArrayListTest.c -o ArrayListTest.o

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)
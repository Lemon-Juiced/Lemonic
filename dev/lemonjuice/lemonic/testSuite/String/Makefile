# Makefile for compiling and linking String and StringTest

CC = gcc
CFLAGS = -I../../ -Wall -Wextra -std=c11

# Object files
OBJ = String.o StringTest.o

# Target executable
TARGET = StringTest

# Default rule
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to compile String.c
String.o: ../../String.c
	$(CC) $(CFLAGS) -c ../../String.c -o String.o

# Rule to compile StringTest.c
StringTest.o: StringTest.c
	$(CC) $(CFLAGS) -c StringTest.c -o StringTest.o

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)
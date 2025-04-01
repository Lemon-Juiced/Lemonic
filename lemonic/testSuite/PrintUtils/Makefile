# Compiler
CC = g++
CFLAGS = -Wall -Wextra -std=c++14

# Source files and object files
SRC = ../../PrintUtils.cpp PrintUtilsTest.cpp
OBJ = $(SRC:.cpp=.o)

# Target executable
TARGET = PrintUtilsTest

# Default rule
all: $(TARGET) clean_objs

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Pattern rule to compile .cpp files into .o files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files after build
clean_objs:
	rm -f $(OBJ)

# Clean rule to remove all build artifacts
clean:
	rm -f $(OBJ) $(TARGET)
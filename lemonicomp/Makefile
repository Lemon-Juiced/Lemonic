# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Object files
OBJ = lemonicomp.o lcomp_prototypes.o lcomp_tokenizer.o

# Target executable
TARGET = lemonicomp

# Default rule
all: $(TARGET) clean_objs

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to compile lemonicomp.c
lemonicomp.o: lemonicomp.c lcomp_prototypes.h lcomp_structs.h lcomp_tokenizer.h
	$(CC) $(CFLAGS) -c lemonicomp.c -o lemonicomp.o

# Rule to compile lcomp_prototypes.c
lcomp_prototypes.o: lcomp_prototypes.c lcomp_prototypes.h lcomp_structs.h lcomp_tokenizer.h
	$(CC) $(CFLAGS) -c lcomp_prototypes.c -o lcomp_prototypes.o

# Rule to compile lcomp_tokenizer.c
lcomp_tokenizer.o: lcomp_tokenizer.c lcomp_tokenizer.h lcomp_structs.h
	$(CC) $(CFLAGS) -c lcomp_tokenizer.c -o lcomp_tokenizer.o

# Rule to clean object files after build
clean_objs:
	rm -f $(OBJ)

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)
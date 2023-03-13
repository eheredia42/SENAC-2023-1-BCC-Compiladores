# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Source files
SRCS = src/interpretador.c

# Object files
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = interpretador

.PHONY: all clean build run

# Default target
all: clean build run

# Build target
build: src/$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean target
clean:
	rm -f $(OBJS) src/$(TARGET)

# Run target
run: src/$(TARGET)
	src/./$(TARGET) src/brainfuck.txt
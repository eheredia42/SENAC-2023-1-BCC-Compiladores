# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Name of executable
EXECUTABLE = main

# Source and object files
SRC = main.c
OBJ = $(SRC:.c=.o)

# Default target
all: build

# Build target
build: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJ) $(EXECUTABLE)

# Run target
run: $(EXECUTABLE)
	./$(EXECUTABLE)
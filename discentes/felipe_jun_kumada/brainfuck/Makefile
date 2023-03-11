CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
LDFLAGS =
TARGET = main

SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c,%.o,$(SRCS))

.PHONY: all clean build run

all: build

build: $(TARGET)

run: build
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
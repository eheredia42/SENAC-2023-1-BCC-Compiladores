CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

TARGET = brainfuck

all: build

build: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $@ $<

run: build
	./$(TARGET) codigo.txt

clean:
	rm -f $(TARGET)
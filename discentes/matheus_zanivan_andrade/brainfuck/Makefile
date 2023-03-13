CC = gcc
LAGS = -Wall

SRC_DIR = src
BUILD_DIR = build

TARGET = $(BUILD_DIR)/main

.PHONY: all clean build run

all: build

build: $(TARGET)

$(TARGET): $(SRC_DIR)/main.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BUILD_DIR)

run: build
	$(TARGET)


CC = gcc
CFLAGS = -Wall -g

SRC = src/main.c
OBJ = main.o
BIN = brainfuck

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

build: all

clean:
	rm -f $(BIN) $(OBJ)

run: all
	./$(BIN) src/entrada.txt
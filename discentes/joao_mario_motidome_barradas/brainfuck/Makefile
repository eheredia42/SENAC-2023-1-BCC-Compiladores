# Makefile

.PHONY: help clean all build 
.SUFFIXES: .c .o 

SRC_DIR=src
CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -std=c99
LDFLAGS= 
LDLIBS=

BIN=brainfuck
SRC=$(wildcard $(SRC_DIR)/*.c)
OBJ=$(SRC:.c=.o)

help: 
	@echo 
	@echo "Uso: make <opção>"
	@echo  
	@echo "    help      : mostra esta mensagem"
	@echo "    clean     : elimina arquivos gerados pelo compilador"
	@echo "    all       : cria binário executável e limpa diretorio" 
	@echo "    build     : cria binário executável" 
	@echo "    run       : roda o execuavel sobre o input (hello.b)" 
	@echo "    tictactoe : roda o execuavel sobre o input (tictactoe.b)" 
	@echo

run: 
	@./bin/brainfuck src/inputs/hello.b 

tictactoe: 
	@./bin/brainfuck src/inputs/ticatactoe.b 

clean:
	@echo "\nLimpando diretorio..\n" 
	@rm -f src/*.o
	@rm -f bin/$(BIN)

build: $(BIN)
	@mv $(BIN) bin/

all: $(BIN)
	echo $1
	@mv $(BIN) bin/
	@rm src/*.o

.c.o:
	@echo "> Compilando [$<]"
	$(CC) $< $(CFLAGS) -c -o $@ 
	@echo

$(BIN): $(OBJ)
	@echo "> Gerando binário executável [$@]"
	$(CC) $^ $(LDFLAGS) $(LDLIBS) -o $@
	@echo

$(OBJ): $(SRC) 

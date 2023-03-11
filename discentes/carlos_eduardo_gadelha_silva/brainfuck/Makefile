all: delete main clean

clean:
	clear

delete: 
	@rm -rf *.o

main: main.c
	gcc -W -Wall main.c funcoes.c funcoes.h -o brainfuck

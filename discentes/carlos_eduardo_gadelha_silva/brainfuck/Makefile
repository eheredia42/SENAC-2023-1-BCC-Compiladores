all: delete main clean

clean:
	clear

delete: 
	@rm -rf src/*.o

main: src/main.c
	gcc -W -Wall src/main.c src/funcoes.c src/funcoes.h -o brainfuck

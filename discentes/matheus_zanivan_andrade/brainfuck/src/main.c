#include <stdio.h>
#include <stdlib.h>

//define o tamanho da memória a ser utilizada pelo programa brainfuck
#define MEM_SIZE 30000

int main() {
	char memory[MEM_SIZE] = {0};//memória do brainfuck
	char *mp = memory;//ponteiro na posicao atual da memória
	char *program;//ponteiro para o código em brainfuck
	char *program_ptr;//ponteiro para posicao atual do programa
	int c;//variavel para leitura de entrada do usuário
	
	
	FILE *file = fopen("brainfuck.txt", "r");
	if (!file){
		printf("Erro: não foi possivel abrir o arquivo\n\n");
		return 1;
	}
	
	// Obtém o tamanho do arquivo
	fseek(file, 0, SEEK_END);
	long file_size = ftell(file);
	fseek(file, 0, SEEK_SET);
	
	// Lê o conteúdo do arquivo para a variável program
	program = malloc(file_size + 1);
	fread(program, file_size, 1, file);
	fclose(file);
	
	//Inicializa o ponteiro para a posição atual do programa
	program_ptr = program;
	
	while (*program_ptr) {
		switch (*program_ptr) {
			case '>':
				mp++;
				break;
			case '<':
				mp--;
				break;
			case '+':
				(*mp)++;
				break;
			case '-':
				(*mp)--;
				break;
			case '.':
				putchar(*mp);
				break;
			case ',':
				c = getchar();
				if (c == EOF) {
					*mp = 0;
				} else {
					*mp = c;
				}
				break;
			case '[':
				if (*mp == 0) {
					int brackets = 1;
					while (brackets != 0) {
						program_ptr++;
						if (*program_ptr == '[') {
							brackets++;
						} else if (*program_ptr == ']') {
							brackets--;
						}
					}
				}
				break;
			case ']':
				if (*mp != 0) {
					int brackets = 1;
					while (brackets != 0) {
						program_ptr--;
						if (*program_ptr == ']') {
							brackets++;
						} else if (*program_ptr == '[') {
							brackets--;
						}
					}
				}
				break;
			default:
				// Ignora qualquer coisa que não seja uma instrução válida de Brainfuck
				break;
		}
		// Avança para a próxima instrução do programa 
		program_ptr++;
	}
	free(program);
	return 0;

}


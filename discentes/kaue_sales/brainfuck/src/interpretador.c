#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 20000

int main(int argc, char *argv[]) {
    FILE *brainfuck = fopen(argv[1], "r");
    
    if (!brainfuck) {
        printf("404: Arquivo não encontrado\n");
        exit(1);
    }
    
    fseek(brainfuck, 0, SEEK_END); //busca o fim do arquivo
    long tamArquivo = ftell(brainfuck); //pega a posição atual
    fseek(brainfuck, 0, SEEK_SET); //volta para a posição inicial do arquivo
    char *code = malloc(tamArquivo + 1);
    fread(code, 1, tamArquivo, brainfuck); //insere os conteúdos do brainfuck no vetor code.
    fclose(brainfuck);
    
    code[tamArquivo] = '\0'; //no final de code, insere um caractere de controle

    char *fita = calloc(CAPACIDADE, sizeof(char));
    char *ponteiro = fita;

    for (int i = 0; code[i] != '\0'; i++) {
        switch (code[i]) {
            case '>': ponteiro++; break;
            case '<': ponteiro--; break;
            case '+': (*ponteiro)++; break;
            case '-': (*ponteiro)--; break;
            case '.': putchar(*ponteiro); break;
            case ',': *ponteiro = getchar(); break;
                
            case '[':
                if (*ponteiro == 0) {
                    int depth = 1;
                    while (depth > 0) {
                        i++;
                        if (code[i] == '[') {
                            depth++;
                        } else if (code[i] == ']') {
                            depth--;
                        }
                    }
                }
                break;
                
            case ']':
                if (*ponteiro != 0) {
                    int depth = 1;
                    while (depth > 0) {
                        i--;
                        if (code[i] == ']') {
                            depth++;
                        } else if (code[i] == '[') {
                            depth--;
                        }
                    }
                }
                break;
            default:
                printf("comando desconhecido \n");
                break;
        }
    }
    
    free(fita);
    free(code);

    return 0;
}

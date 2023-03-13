#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROFUNDIDADE 100
int main(int argc, char *argv[]) {
    //Verificações no arquivo
    if (argc < 2) {
        printf("Uso: %s [file]\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", argv[1]);
        return 1;
    }

    // Alocando memória para o array
    char *mem = calloc(30000, sizeof(char));
    
    //Inicializando variaveis
    char c;
    int i = 0; 
    int profundidade = 0;
    int iniLoop[MAX_PROFUNDIDADE];

    // Lendo cada caractere do arquivo com o código Brainfuck
    while ((c = fgetc(file)) != EOF) {
        switch (c) {
            case '>': 
                i++;
                break;
            case '<': 
                i--;
                break;
            case '+':
                mem[i]++;
                break;
            case '-': 
                mem[i]--;
                break;
            case '.': 
                putchar(mem[i]);
                break;
            case ',': 
                mem[i] = getchar();
                break;
            case '[': 
            //Caso o valor atual seja 0 --> vai pro final do loop
                if (mem[i] == 0) { 
                    profundidade++;
                    while (profundidade > 0) {
                        c = fgetc(file);
                        if (c == '[') {
                            profundidade++;
                        } else if (c == ']') {
                            profundidade--;
                        }
                    }
                } else {
                    iniLoop[profundidade] = ftell(file) - 1;
                    profundidade++;
                }
                break;
            case ']':
                profundidade--;
                if (mem[i] != 0) {
                    fseek(file, iniLoop[profundidade], SEEK_SET);
                }
                break;~
            //ignora qualquer outro caractere que não seja + - > < . , [ ]
            default:
                break;
        }
    }

    // Libera memoria
    free(mem);
    fclose(file);

    return 0;
}
